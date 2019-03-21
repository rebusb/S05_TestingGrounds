// 2019 RebusStudios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicGun.generated.h"

class ABallProjectile;
class USkeletalMeshComponent;
class USceneComponent;
class USoundBase;
class UAnimMontage;
class UAnimInstance;

UCLASS()
class TESTINGGROUNDS_API ABasicGun : public AActor
{
	GENERATED_BODY()

	/** Gun mesh:visible*/
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* GunMesh;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* MuzzleLocation;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABallProjectile> ProjectileClass;
public:
	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimInstance* AnimInstance;

	// Sets default values for this actor's properties
	ABasicGun();

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/** Fires a projectile. */
	UFUNCTION(BlueprintCallable)
	void OnFire();
	
	
};
