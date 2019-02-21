// 2019 RebusStudios

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//get PatrolPoint array (reference) via PatrollingGuard Pawn
	AAIController* AIController = OwnerComp.GetAIOwner();
	APatrollingGuard* GuardPawn = Cast<APatrollingGuard>(AIController->GetPawn());
	if (!ensure(GuardPawn)) { return  EBTNodeResult::Aborted; };			//dump out of function on bad pointer...
	TArray<AActor *>& PatrolPoints = GuardPawn->PatrolPoints;

	//get current index
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 IndexValue = BlackboardComp->GetValueAsInt(Index.SelectedKeyName);

	//get waypoint
	if (!ensure(PatrolPoints.IsValidIndex(IndexValue))) { return EBTNodeResult::Failed; }	// fail out on lack of PatrolPoints, maybe there are no points set.
	AActor* NextWaypoint = PatrolPoints[IndexValue];

	//set Waypoint
	if (!ensure(NextWaypoint)) { return  EBTNodeResult::Aborted; };			//dump out of function on bad pointer...
	BlackboardComp->SetValueAsObject(Waypoint.SelectedKeyName, NextWaypoint);

	//advance index
	int32 NextIndex = (IndexValue+1)%PatrolPoints.Num();

	//set Index
	BlackboardComp->SetValueAsInt(Index.SelectedKeyName, NextIndex);

	UE_LOG(LogTemp, Warning, TEXT("ChooseNextWaypoint Guard:%s current Waypoint:%s next waypoint index:%i"), 
		*GuardPawn->GetName(),
		*NextWaypoint->GetName(),
		NextIndex);


	return EBTNodeResult::Succeeded;
}
