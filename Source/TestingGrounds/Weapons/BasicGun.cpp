// 2019 RebusStudios

#include "BasicGun.h"
#include "BallProjectile.h"
#include "Components/SkeletalMeshComponent.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimMontage.h"
#include "Animation/AnimInstance.h"

// Sets default values
ABasicGun::ABasicGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a gun mesh component
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	check(GunMesh != nullptr);	// fail if no gun mesh
	GunMesh->bCastDynamicShadow = true;
	GunMesh->CastShadow = true;
	// GunMesh->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	SetRootComponent(GunMesh);

	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));


	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);


}

// Called when the game starts or when spawned
void ABasicGun::BeginPlay()
{
	Super::BeginPlay();
	if (ensure(MuzzleLocation))
	{
		MuzzleLocation->SetupAttachment(GunMesh, FName("Muzzle"));
		MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));
	}

	}


void ABasicGun::OnFire()
{
	// try and fire a projectile
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{

			const FRotator SpawnRotation =MuzzleLocation->GetComponentRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = MuzzleLocation->GetComponentLocation();

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			World->SpawnActor<ABallProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No ProjectileClass set in gun!!!"));
	}

	// try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	// TODO need to connect firing animation to pawn mesh that is holding gun... tbd
	if (FireAnimation != nullptr)
	{
		
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}