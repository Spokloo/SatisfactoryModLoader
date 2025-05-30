// This file has been automatically generated by the Unreal Header Implementation tool

#include "ShoppingList/FGShoppingListComponent.h"
#include "Net/UnrealNetwork.h"

UFGShoppingListComponent* UFGShoppingListComponent::GetShoppingListComponent(const  APlayerController* playerController){ return nullptr; }
UFGShoppingListComponent::UFGShoppingListComponent() : Super() {

}
void UFGShoppingListComponent::GetShoppingListObjects(TArray<class UFGShoppingListObject*>& out_ShoppingListObjects){ }
UFGShoppingListObject* UFGShoppingListComponent::GetShoppingListObjectFromClass(TSubclassOf<UObject> objectClass, bool& out_result){ return nullptr; }
UFGShoppingListObject* UFGShoppingListComponent::GetShoppingListObjectFromObject(UObject* object, bool& out_result){ return nullptr; }
TArray< FItemAmount > UFGShoppingListComponent::GetShoppingListCost() const{ return TArray<FItemAmount>(); }
void UFGShoppingListComponent::RemoveFromShoppingList(TSubclassOf< UObject > inClass){ }
void UFGShoppingListComponent::RemoveAmountFromShoppingList(TSubclassOf< UObject > inClass, int32 amountToRemove){ }
void UFGShoppingListComponent::RemoveBlueprintFromShoppingList(const FString& blueprintName, int32 amountToRemove){ }
void UFGShoppingListComponent::ClearShoppingList(){ }
void UFGShoppingListComponent::MigrateShoppingList(TArray< FShoppingListRecipeEntry > recipeEntries){ }
void UFGShoppingListComponent::OnBlueprintRemoved(const FString& blueprintName){ }
void UFGShoppingListComponent::UpdateShoppingListObjectBlueprint( UFGShoppingListObject_Object* shoppingListObject_Object){ }
void UFGShoppingListComponent::UpdateShoppingListObjectClass( UFGShoppingListObject_Class* shoppingListObject_Class){ }
void UFGShoppingListComponent::UpdateShoppingList(){ }
void UFGShoppingListComponent::BeginPlay(){ Super::BeginPlay(); }
void UFGShoppingListComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFGShoppingListComponent, mShoppingListBlueprints);
	DOREPLIFETIME(UFGShoppingListComponent, mShoppingListClassEntries);
}
void UFGShoppingListComponent::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
void UFGShoppingListComponent::CopyComponentProperties_Implementation(UActorComponent* intoComponent){ }
void UFGShoppingListComponent::Server_SetNumBlueprintsInShoppingList_Implementation(const FString& blueprintName, int32 totalAmount){ }
void UFGShoppingListComponent::Server_SetNumForClassInShoppingList_Implementation(TSubclassOf<  UObject > inClass, int32 totalAmount){ }
void UFGShoppingListComponent::Server_ClearShoppingList_Implementation(){ }
void UFGShoppingListComponent::BroadcastShoppingListUpdated() const{ }
bool UFGShoppingListComponent::OwnerHasAuthority() const{ return bool(); }
bool UFGShoppingListComponent::OwnerHasLocalNetOwner() const{ return bool(); }
void UFGShoppingListComponent::OnRep_ShoppingListBlueprints(){ }
void UFGShoppingListComponent::OnBlueprintAvailable( UFGBlueprintDescriptor* blueprintDescriptor){ }
void UFGShoppingListComponent::SetupInitialShoppingListObjectForBlueprints(){ }
void UFGShoppingListComponent::SetupBlueprintFromBlueprintEntry( UFGBlueprintDescriptor* blueprintDescriptor, int32 amount){ }
void UFGShoppingListComponent::OnRep_ShoppingListClassEntries(){ }
void UFGShoppingListComponent::SetupInitialShoppingListObjectForClassEntries(){ }
