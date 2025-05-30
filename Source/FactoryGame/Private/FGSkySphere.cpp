// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGSkySphere.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

FSkySphereSettings::FSkySphereSettings(){ }
#if WITH_EDITOR
void AFGSkySphere::PostEditChangeChainProperty( FPropertyChangedChainEvent& propertyChangedEvent){ }
#endif 
#if WITH_EDITOR
float AFGSkySphere::GetViewMinInput() const{ return float(); }
float AFGSkySphere::GetViewMaxInput() const{ return float(); }
void AFGSkySphere::SetViewRange(float min, float max){ }
#endif 
#if WITH_EDITOR
void AFGSkySphere::SetupPreviewDelegate(){ }
#endif 
#if WITH_EDITORONLY_DATA
#endif 
AFGSkySphere::AFGSkySphere() : Super() {
	this->mDefaultMaterial = nullptr;
	this->mDefaultLowSpecMaterial = nullptr;
	this->mDefaultMesh = nullptr;
	this->mSkyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SkySphere"));
	this->mSkyMeshComponent->SetMobility(EComponentMobility::Static);
	this->mWeatherChangeDelayTime = FFloatInterval(3.40282e+38, -3.40282e+38);
	this->mRainOcclusionSceneCapture2DComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("OcclusionSceneCapture"));
	this->mRainOcclusionSceneCapture2DComponent->SetMobility(EComponentMobility::Movable);
	this->mRainOcclusionRT = nullptr;
	this->mRainOcclusionMaterialParameterCollection = nullptr;
	this->mTimeOfDayCollection = nullptr;
	this->mRainOcclusionActor = nullptr;
	this->mDefaultRainOcclusionActorClass = nullptr;
	this->mRainCaptureDistance = 10000.0;
	this->mSceneCaptureGridSnap = 0.0;
	this->mSunLightColorCurve.ExternalCurve = nullptr;
	this->mSunIntensity.EditorCurveData.DefaultValue = 4.0;
	this->mSunIntensity.EditorCurveData.PreInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mSunIntensity.EditorCurveData.PostInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mSunIntensity.ExternalCurve = nullptr;
	this->mSunRotationPitch.EditorCurveData.DefaultValue = 3.40282e+38;
	this->mSunRotationPitch.EditorCurveData.PreInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mSunRotationPitch.EditorCurveData.PostInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mSunRotationPitch.ExternalCurve = nullptr;
	this->mMoonLightColorCurve.ExternalCurve = nullptr;
	this->mMoonIntensity.EditorCurveData.DefaultValue = 3.40282e+38;
	this->mMoonIntensity.EditorCurveData.PreInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mMoonIntensity.EditorCurveData.PostInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mMoonIntensity.ExternalCurve = nullptr;
	this->mMoonRotationPitch.EditorCurveData.DefaultValue = 3.40282e+38;
	this->mMoonRotationPitch.EditorCurveData.PreInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mMoonRotationPitch.EditorCurveData.PostInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mMoonRotationPitch.ExternalCurve = nullptr;
	this->mOcclusionTintColor.ExternalCurve = nullptr;
	this->mSkyLightColor.ExternalCurve = nullptr;
	this->mCurrentLight = nullptr;
	this->mSkyLight = nullptr;
	this->mSunLight = nullptr;
	this->mMoonLight = nullptr;
	this->mClouds = nullptr;
	this->mSunOriginRotation = FRotator(0, 45, 25);
	this->mSunRotationAxis = FRotator(55, 190, 0);
	this->mMoonOriginRotation = FRotator(0, 45, 25);
	this->mMoonRotationAxis = FRotator(55, 190, 0);
	this->mDayTickRate = 0.1;
	this->mNightTickRate = 0.05;
	this->mCachedTimeOfDaySubSystem = nullptr;
	this->PrimaryActorTick.TickGroup = ETickingGroup::TG_EndPhysics;
	this->PrimaryActorTick.EndTickGroup = ETickingGroup::TG_PrePhysics;
	this->PrimaryActorTick.bTickEvenWhenPaused = false;
	this->PrimaryActorTick.bCanEverTick = true;
	this->PrimaryActorTick.bStartWithTickEnabled = true;
	this->PrimaryActorTick.bAllowTickOnDedicatedServer = true;
	this->PrimaryActorTick.TickInterval = 0.0;
	this->bReplicates = true;
	this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	this->RootComponent->SetMobility(EComponentMobility::Static);
	this->mRainOcclusionSceneCapture2DComponent->SetupAttachment(RootComponent);
}
void AFGSkySphere::PostActorCreated(){ Super::PostActorCreated(); }
void AFGSkySphere::PostLoad(){ Super::PostLoad(); }
void AFGSkySphere::BeginDestroy(){ Super::BeginDestroy(); }
void AFGSkySphere::Tick(float DeltaTime){ Super::Tick(DeltaTime); }
void AFGSkySphere::BeginPlay(){ Super::BeginPlay(); }
void AFGSkySphere::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGSkySphere, mCurrentSelectedWeather);
}
void AFGSkySphere::OnConstruction(const FTransform& Transform){ }
void AFGSkySphere::UpdateMaterial(bool bWithVolumetricClouds){ }
void AFGSkySphere::SetDirectionalLightIntensityMultiplierOverride(float multiplier){ }
float AFGSkySphere::GetDirectionalLightIntensityMultiplierOverride(){ return float(); }
FWeatherChanceEntry AFGSkySphere::GetNewWeatherState(){ return FWeatherChanceEntry(); }
void AFGSkySphere::SetWeatherState(int32 NewTypeID){ }
void AFGSkySphere::OnRep_OnWeatherChanged(int32 OldState){ }
void AFGSkySphere::SetCloudShadowIntensity(float NewValue){ }
float AFGSkySphere::GetCloudShadowIntensity() const{ return float(); }
void AFGSkySphere::TryUpdateSceneCaptureLocation(bool bForce){ }
void AFGSkySphere::UpdateOcclusionDistance(){ }
void AFGSkySphere::UpdateLightRotation(){ }
void AFGSkySphere::UpdateCurvesFromTime(){ }
void AFGSkySphere::CalculateDominantLight(){ }
void AFGSkySphere::UpdateDominantLight(ADirectionalLight* NewDominantLight){ }
FRotator AFGSkySphere::CalculateLightRotation(FRotator OriginalRotation, FRotator RotationAxis, FRuntimeFloatCurve LightRotationCurve) const{ return FRotator(); }
bool AFGSkySphere::CanUpdate(){ return bool(); }
bool AFGSkySphere::CanUpdatePreview() const{ return bool(); }
void AFGSkySphere::ApplySkySphereSettings_Implementation(const FSkySphereSettings& settings){ }
void AFGSkySphere::UpdatePreview(){ }
FLinearColor AFGSkySphere::GetColorCurveValue(const FRuntimeCurveLinearColor& curve, float time){ return FLinearColor(); }
float AFGSkySphere::GetFloatCurveValue(const FRuntimeFloatCurve& curve, float time){ return float(); }
void AFGSkySphere::GetSkySphereSettings(float atTime, FSkySphereSettings& out_settings) const{ }
bool AFGSkySphere::DoesWeatherEffectNeedOcclusion(const FWeatherChanceEntry& Type){ return bool(); }
void AFGSkySphere::UpdateGlobalMaterialCollection(){ }
