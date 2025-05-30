// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "FactoryGame.h"
#include "Engine/DeveloperSettings.h"
#include "Resources/FGItemDescriptor.h"
#include "Resources/FGResourceNode.h"
#include "FGResourceSettings.generated.h"

enum class EFGCrateType : uint8;
/**  */
USTRUCT( BlueprintType )
struct FACTORYGAME_API FResourceDepositPackage
{
	GENERATED_BODY()

	/** Chance in roulette selection to get the package */
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "ResourceDepositPackage" )
	float DropChance = 0.f;

	/** What resource class to use */
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "ResourceDepositPackage" )
	TSoftClassPtr< class UFGResourceDescriptor > ResourceClass;

	/** Amount of resources in deposit as minimum */
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "ResourceDepositPackage" )
	int32 MinAmount = 0;

	/** Amount of resources in deposit as max */
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "ResourceDepositPackage" )
	int32 MaxAmount = 0;

	/** How much to get per "mine cycle" */
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "ResourceDepositPackage" )
	int32 MiningAmount = 0;
};

UCLASS( config = Game, defaultconfig, meta = ( DisplayName = "Resource Settings" ) )
class FACTORYGAME_API UFGResourceSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	/** Helper to directly get the resource setting without going through UFGGlobalSettings */
	static const UFGResourceSettings* Get() { return GetDefault<UFGResourceSettings>(); }

	/** Get a random resource deposit package */
	UFUNCTION( BlueprintPure, Category = "ResourceDepositPackage" )
	static const FResourceDepositPackage& GetRandomResourceDepositData( int32& out_resourceDepositPackageIdx, const bool canBeRadioActive );

	/** Gets deposit data with a specified resource class
	 * returns false if no deposit data existed with that resource class */
	UFUNCTION( BlueprintPure, Category = "ResourceDepositPackage" )
	static const FResourceDepositPackage& GetResourceDepositDataFromClass( TSubclassOf< class UFGResourceDescriptor > desiredResourceClass, int32& out_resourceDepositPackageIdx, AActor* worldContext );

	/** Gets the size of a Given Stack Size enum from the stack size TMap */
	UFUNCTION( BlueprintPure, Category = "Resources" )
	int32 GetStackSizeFromEnum( EStackSize stackSize ) const;

	/** List of all available resource deposit packages */
	UPROPERTY( Config, EditAnywhere, Category = "ResourceDepositPackage" )
	TArray< FResourceDepositPackage > mResourceDepositTable;
	
	/** Index 0 is poor amount, 1 is normal and 2 is rich */
	UPROPERTY( Config, EditDefaultsOnly, EditFixedSize, Category = "Resources" )
	TArray< FInt32Interval > mResourceAmount;

	/** Index 0 is poor amount, 1 is normal and 2 is rich */
	UPROPERTY( Config, EditDefaultsOnly, EditFixedSize, Category = "Resources" )
	TArray< float > mPurityMultiplier;

	UPROPERTY( Config, EditDefaultsOnly, Category = "Resources" )
	TSoftClassPtr< class UFGResourceDescriptor > mWaterResourceDescriptor; 

	/** Mesh used on items that do not have their own specified. */
	UPROPERTY( Config, EditDefaultsOnly, Category = "Buildable" )
	TSoftObjectPtr<UStaticMesh> mDefaultItemMesh;

	/** How many of diffrent items can be in the same stack */
	UPROPERTY( Config, EditDefaultsOnly, Category = "Items" )
	TMap< int32, EStackSize > mStackSizes;

	/** The class of item we want to drop when we drop something */
	UPROPERTY( Config, EditDefaultsOnly, Category = "Drops" )
	TSoftClassPtr< class AFGItemPickup_Spawnable > mItemDropClass;

	/** Distance, in centimeters (unreal units), below which item drops will be added into the existing crate, rather than creating a new one */
	UPROPERTY( EditAnywhere, Config, Category = "Drops" )
	TMap<EFGCrateType, float> mInventoryCrateMergeDistance;
	
	UPROPERTY( Config, EditDefaultsOnly, Category = "Power" )
	TMap< TEnumAsByte< EResourcePurity >, TSoftObjectPtr<class UCurveFloat> > mGeyserPowerOutputCurves;
};
