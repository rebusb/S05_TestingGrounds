// 2019 RebusStudios

#include "PatrolRouteComponent.h"


// Sets default values for this component's properties
UPatrolRouteComponent::UPatrolRouteComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UPatrolRouteComponent::BeginPlay()
{
	Super::BeginPlay();

	if (PatrolPoints.Num()<=0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Has NO Patrol Points!!"), *GetOwner()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Will be Patrolling %i Points."), *GetOwner()->GetName(), PatrolPoints.Num());
	}
}


// Called every frame
void UPatrolRouteComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

const TArray<AActor*>& UPatrolRouteComponent::GetPatrolPoints()
{
	return PatrolPoints;
}