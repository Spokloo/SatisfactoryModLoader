// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGPlayerCinematicProxy.h"

#if WITH_EDITOR
void UFGPlayerCinematicDriver::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent){ Super::PostEditChangeProperty(PropertyChangedEvent); }
void UFGPlayerCinematicDriver::PostEditChangeCinematicPlayerSettings(FPropertyChangedEvent& PropertyChangedEvent){ }
#endif 
UFGPlayerCinematicDriver::UFGPlayerCinematicDriver() : Super() {
	this->mViewRotation = FRotator::ZeroRotator;
	this->mWantsToSprint = false;
	this->mWantsToCrouch = false;
	this->mWantsToJump = false;
	this->mPrimaryFireTimeLeft = 0.0;
	this->mSecondaryFireTimeLeft = 0.0;
	this->mLastActorLocation = FVector::ZeroVector;
	this->mCinematicPlayerState = nullptr;
}
UWorld* UFGPlayerCinematicDriver::GetWorld() const{ return nullptr; }
void UFGPlayerCinematicDriver::AttachToOwner(){ }
void UFGPlayerCinematicDriver::OwnerBeginPlay(){ }
void UFGPlayerCinematicDriver::UpdateCinematicDriver(float deltaTime){ }
void UFGPlayerCinematicDriver::DestroyCinematicDriver(){ }
FRotator UFGPlayerCinematicDriver::GetDesiredRotation(FRotator currentRotation) const{ return FRotator(); }
void UFGPlayerCinematicDriver::EquipItemFromInventory(TSubclassOf<UFGEquipmentDescriptor> equipmentDescriptor, bool makeIndexActive){ }
void UFGPlayerCinematicDriver::PlayEmote(TSubclassOf<class UFGEmote> emote){ }
void UFGPlayerCinematicDriver::ToggleEquipmentHolster(){ }
void UFGPlayerCinematicDriver::SetSelectedEquipmentIndex(int32 newSelectedArmsIndex){ }
void UFGPlayerCinematicDriver::EquipmentPrimaryFire(float holdDuration){ }
void UFGPlayerCinematicDriver::EquipmentSecondaryFire(float holdDuration){ }
void UFGPlayerCinematicDriver::EquipmentReload(){ }
void UFGPlayerCinematicDriver::EquipmentChangeAmmoType(TSubclassOf< UFGAmmoType > newDesiredAmmoClass){ }
void UFGPlayerCinematicDriver::Internal_RefreshInventoryItems(){ }
void UFGPlayerCinematicDriver::EquipItemsFromInventory(){ }
void UFGPlayerCinematicDriver::UpdateDefaultInventoryItems() const{ }
