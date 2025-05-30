// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGConveyorChainActor.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "Net/UnrealNetwork.h"

AFGConveyorChainActor::AFGConveyorChainActor() : Super() {
	this->mSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	this->mSceneComponent->SetMobility(EComponentMobility::Movable);
	this->mSplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	this->mSplineComponent->SetupAttachment(mSceneComponent);
	this->mSplineComponent->SetMobility(EComponentMobility::Movable);
	this->mFirstConveyor = nullptr;
	this->mLastConveyor = nullptr;
	this->mConnection0 = nullptr;
	this->mConnection1 = nullptr;
	this->mTotalLength = 0.0;
	this->mLeadItemIndex = -1;
	this->mTailItemIndex = -1;
	this->mItemRemovals.CurrentSubsystemTime = 0.0;
	this->mItemRemovals.ChainActor = nullptr;
	this->mItemAdditions.CurrentSubsystemTime = 0.0;
	this->mItemAdditions.ChainActor = nullptr;
	this->mConveyorChainSubsystem = nullptr;
	this->mSpeedOfSlowestBelt = 0.0;
	this->bReplicates = true;
	this->RootComponent = mSceneComponent;
}
void AFGConveyorChainActor::BeginPlay(){ Super::BeginPlay(); }
void AFGConveyorChainActor::EndPlay(const EEndPlayReason::Type endPlayReason){ Super::EndPlay(endPlayReason); }
void AFGConveyorChainActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGConveyorChainActor, mTotalLength);
	DOREPLIFETIME(AFGConveyorChainActor, mItemRemovals);
	DOREPLIFETIME(AFGConveyorChainActor, mItemAdditions);
	DOREPLIFETIME(AFGConveyorChainActor, mSpeedOfSlowestBelt);
}
void AFGConveyorChainActor::Tick(float DeltaSeconds){ Super::Tick(DeltaSeconds); }
void AFGConveyorChainActor::Serialize(FArchive& ar){ Super::Serialize(ar); }
void AFGConveyorChainActor::BuildLUT(){ }
void AFGConveyorChainActor::NotifyActorChannelClosedForNetConnection(UNetConnection* NetConnection){ }
void AFGConveyorChainActor::Factory_Tick(float deltaTime){ }
void AFGConveyorChainActor::Factory_EnqueueItem(const FInventoryItem& item, float initialOffset, float timeDebt){ }
bool AFGConveyorChainActor::Factory_PeekOutput(TArray< FInventoryItem >& out_items, TSubclassOf< UFGItemDescriptor > type){ return bool(); }
bool AFGConveyorChainActor::Factory_GrabOutput(FInventoryItem& out_item, TSubclassOf< UFGItemDescriptor > type){ return bool(); }
void AFGConveyorChainActor::Factory_RemoveItemAt(int32 index, TSubclassOf< UFGItemDescriptor> expectedClass){ }
void AFGConveyorChainActor::RemoveItemAt_Internal(int32 index){ }
void AFGConveyorChainActor::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
void AFGConveyorChainActor::SetStartAndEndConveyors(AFGBuildableConveyorBase* start, AFGBuildableConveyorBase* end){ }
void AFGConveyorChainActor::SanitizeItemsFromLoad(){ }
void AFGConveyorChainActor::RegisterWithSubsystem(){ }
void AFGConveyorChainActor::RevertChainActor(){ }
bool AFGConveyorChainActor::BuildChain(){ return bool(); }
void AFGConveyorChainActor::RebuildSplineComponent(int32 reparamStepsPerSeg){ }
void AFGConveyorChainActor::MoveItemsFromBeltsToChain(){ }
void AFGConveyorChainActor::MoveItemsFromChainToBelts(){ }
void AFGConveyorChainActor::ClientMoveItemsFromChainToBelts(){ }
void AFGConveyorChainActor::NetUpdateBuildSpline(){ }
void AFGConveyorChainActor::NetUpdateBuildItemsFromRanges(int32 numItems, const TArray< FConveyorItemDescRange >& descRanges, const TArray< FConveyorItemSpacingRange >& spacingRanges, int32 currentRemovalIndex, int32 currentAdditionIndex){ }
void AFGConveyorChainActor::MarkChainForItemUpdate(){ }
int32 AFGConveyorChainActor::GetNumItemsInSegment(const FConveyorChainSplineSegment& splineSegment) const{ return int32(); }
int32 AFGConveyorChainActor::GetNumActualItems() const{ return int32(); }
bool AFGConveyorChainActor::IsItemIndexValid(int32 index) const{ return bool(); }
bool AFGConveyorChainActor::IsItemIndexValidForSegment(FConveyorChainSplineSegment* segment, int32 index) const{ return bool(); }
int32 AFGConveyorChainActor::GetIndexDistanceFromLeadItem(int32 index) const{ return int32(); }
FConveyorBeltItem* AFGConveyorChainActor::GetItemForIndex(int32 index){ return nullptr; }
void AFGConveyorChainActor::GetItemsForSegment( AFGBuildableConveyorBase* conveyorBase, TArray< FConveyorBeltItem* >& out_Items){ }
void AFGConveyorChainActor::GetItemsForSegmentIndex(int32 segIndex, TArray< FConveyorBeltItem* >& out_Items){ }
FConveyorBeltItem* AFGConveyorChainActor::FindItemClosestToLocation(const FVector& location, bool discountLifts, int32& out_ItemIndex, TSubclassOf<  UFGItemDescriptor > desiredClass, EChainItemSearchDirection dir){ return nullptr; }
FConveyorBeltItem* AFGConveyorChainActor::FindItemClosestToOffset(float offset, float maxDistance, bool discountLifts,  int32& out_ItemIndex, TSubclassOf<  UFGItemDescriptor > desiredClass, EChainItemSearchDirection dir){ return nullptr; }
FConveyorBeltItem* AFGConveyorChainActor::FindItemPickupForClient(float offset, TSubclassOf< UFGItemDescriptor > desiredClass, int32& out_ItemIndex){ return nullptr; }
FVector AFGConveyorChainActor::GetLocationAtDistanceAlongSpline(float offset, ESplineCoordinateSpace::Type cordSpace) const{ return FVector(); }
FVector AFGConveyorChainActor::GetDirectionAtDistanceAlongSpline(float offset, ESplineCoordinateSpace::Type cordSpace) const{ return FVector(); }
void AFGConveyorChainActor::GetLocationAndRotationOfItem(int32 index, FVector& out_Location, FRotator& out_Rotation){ }
float AFGConveyorChainActor::FindOffsetClosestToLocation(const FVector& location){ return float(); }
FConveyorChainSplineSegment* AFGConveyorChainActor::GetSegmentForConveyorBase(AFGBuildableConveyorBase* conveyorBase){ return nullptr; }
FConveyorChainSplineSegment* AFGConveyorChainActor::GetSegmentForItemIndex(int32 itemIndex){ return nullptr; }
FConveyorChainSplineSegment* AFGConveyorChainActor::GetSegmentForOffset(float offset){ return nullptr; }
bool AFGConveyorChainActor::HasRoomOnChain(float& out_availableSpace){ return bool(); }
float AFGConveyorChainActor::GetAvailableSpace(){ return float(); }
void AFGConveyorChainActor::InitializeConveyorItemArray(){ }
void AFGConveyorChainActor::AddClientAvailableConveyor( AFGBuildableConveyorBase* conveyorBase){ }
void AFGConveyorChainActor::RemoveClientAvailableConveyor( AFGBuildableConveyorBase* conveyorBase){ }
void AFGConveyorChainActor::HandleClientRemovals(){ }
void AFGConveyorChainActor::HandleClientAdditions(){ }
void AFGConveyorChainActor::AddConnectionEntryForItemStateIndices(UNetConnection* connection){ }
void AFGConveyorChainActor::RemoveConnectionEntryForItemStateIndices(UNetConnection* connection){ }
uint8 AFGConveyorChainActor::EstimatedMaxNumGrab_Threadsafe(float estimatedDeltaTime) const{ return uint8(); }
float AFGConveyorChainActor::GetAndUseTimeDebtForItem(int32 itemIndex, float dt){ return float(); }
void AFGConveyorChainActor::RegisterConveyorMonitor(class AFGBuildableConveyorMonitor* monitor){  }
void AFGConveyorChainActor::UnregisterConveyorMonitor(class AFGBuildableConveyorMonitor* monitor){  }
void AFGConveyorChainActor::UpdateAttachedMonitors(float deltaTime){ }
void AFGConveyorChainActor::DebugDrawChainInfo(){ }
void AFGConveyorChainActor::DebugDrawItemTimeDebt(int32 itemIndex){ }
