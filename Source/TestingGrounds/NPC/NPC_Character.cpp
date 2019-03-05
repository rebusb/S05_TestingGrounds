// 2019 RebusStudios

#include "NPC_Character.h"


// Sets default values
ANPC_Character::ANPC_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	// Create a gun mesh component
	NPC_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("NPC_Gun"));
	check(NPC_Gun != nullptr);	// fail if no gun mesh
	NPC_Gun->bCastDynamicShadow = true;
	NPC_Gun->CastShadow = true;
	// NPC_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	NPC_Gun->SetupAttachment(RootComponent);

	NPC_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	NPC_MuzzleLocation->SetupAttachment(NPC_Gun);
	NPC_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P, NPC_Gun, and VR_Gun 
	// are set in the derived blueprint asset named MyCharacter to avoid direct content references in C++.
}

// Called when the game starts or when spawned
void ANPC_Character::BeginPlay()
{
	Super::BeginPlay();


	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	NPC_Gun->AttachToComponent (GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	NPC_Gun->SetHiddenInGame(false, true);

}

// Called every frame
void ANPC_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

