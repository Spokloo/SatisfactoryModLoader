// This file has been automatically generated by the Unreal Header Implementation tool

#include "UI/FGOptionsValueController.h"

void UFGOptionsValueController::InitValueController(FOptionRowData optionRowData, UFGDynamicOptionsRow* parentOptionRow, TScriptInterface<  IFGOptionInterface > optionInterface){ }
void UFGOptionsValueController::InitValueController( UFGUserSetting* userSetting, UFGDynamicOptionsRow* parentOptionRow, TScriptInterface<  IFGOptionInterface > optionInterface){ }
bool UFGOptionsValueController::IsPendingApply_Implementation(){ return bool(); }
bool UFGOptionsValueController::IsPendingRestart_Implementation(){ return bool(); }
bool UFGOptionsValueController::ShouldBeClickable_Implementation(){ return bool(); }
bool UFGOptionsValueController::HandleResetValueDetails_Implementation(FFGKeyHint& KeyHint){ return bool(); }
bool UFGOptionsValueController::HandleActivateDetails_Implementation(FFGKeyHint& KeyHint){ return bool(); }
void UFGOptionsValueController::OnOptionReverted_Implementation(){ }
FText UFGOptionsValueController::GetCurrentSelectionText(){ return FText(); }
bool UFGOptionsValueController::IsOptionEditable() const{ return bool(); }
bool UFGOptionsValueController::ShouldFocusOptionSlotToEdit() const{ return false; }
bool UFGOptionsValueController::CanSelectIndex(int32 newIndex){ return bool(); }
bool UFGOptionsValueController::ChangeSelection(FText currentKey, bool incrementSelection){ return bool(); }
FString UFGOptionsValueController::GetSettingIndentifier() const{ return FString(); }
TArray<FIntegerSelection> UFGOptionsValueController::GetIntegerSelectionValues() const{ return TArray<FIntegerSelection>(); }
bool UFGOptionsValueController::GetBlockLastIndexFromManualSelection() const{ return bool(); }
EOptionType UFGOptionsValueController::GetOptionType() const{ return EOptionType(); }
void UFGOptionsValueController::NativeConstruct(){ Super::NativeConstruct(); }
bool UFGOptionsValueController::GetBoolOptionValue(){ return bool(); }
FOptionRowData UFGOptionsValueController::GetOptionRowData() const{ return FOptionRowData(); }
