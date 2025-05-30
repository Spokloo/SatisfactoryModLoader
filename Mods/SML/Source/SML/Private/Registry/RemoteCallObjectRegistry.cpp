#include "Registry/RemoteCallObjectRegistry.h"
#include "FGGameMode.h"
#include "Engine/GameInstance.h"
#include "Player/SMLRemoteCallObject.h"
#include "GameFramework/GameModeBase.h"
#include "SessionSettings/SessionSettingsSubsystem.h"

void URemoteCallObjectRegistry::RegisterRemoteCallObject(TSubclassOf<UFGRemoteCallObject> RemoteCallObject) {
    check(RemoteCallObject);
    RegisteredRCOs.AddUnique(RemoteCallObject);
}

void URemoteCallObjectRegistry::Initialize(FSubsystemCollectionBase& Collection) {
    RegisterRemoteCallObject(USMLRemoteCallObject::StaticClass());
    RegisterRemoteCallObject(USMLSessionSettingsRemoteCallObject::StaticClass());
}

void URemoteCallObjectRegistry::RegisterRCOsOnGameMode(AGameModeBase* GameMode) {
    UGameInstance* OwnerGameInstance = GameMode->GetWorld()->GetGameInstance();
    URemoteCallObjectRegistry* Registry = OwnerGameInstance->GetSubsystem<URemoteCallObjectRegistry>();
    AFGGameMode* FactoryGameMode = Cast<AFGGameMode>(GameMode);
    if (FactoryGameMode != NULL) {
        for (const TSubclassOf<UFGRemoteCallObject>& RCO : Registry->RegisteredRCOs) {
            FactoryGameMode->RegisterRemoteCallObjectClass(RCO);
        }
    }
}

void URemoteCallObjectRegistry::InitializePatches() {
    FGameModeEvents::GameModeInitializedEvent.AddStatic(URemoteCallObjectRegistry::RegisterRCOsOnGameMode);
}
