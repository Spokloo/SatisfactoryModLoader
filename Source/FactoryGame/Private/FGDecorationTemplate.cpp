// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGDecorationTemplate.h"
#include "Components/SceneComponent.h"

#if WITH_EDITORONLY_DATA
#endif 
AFGDecorationTemplate::AFGDecorationTemplate() : Super() {
	this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	this->RootComponent->SetMobility(EComponentMobility::Static);
}
TArray< class UFGPoolableProxyComponentBase* > AFGDecorationTemplate::GetPoolAbleComponentsFromSubclass(const UClass* InActorClass){ return TArray<class UFGPoolableProxyComponentBase*>(); }
TArray< class USceneComponent* > AFGDecorationTemplate::GetSignificantComponentsFromSubclass(const UClass* InActorClass){ return TArray<class USceneComponent*>(); }
