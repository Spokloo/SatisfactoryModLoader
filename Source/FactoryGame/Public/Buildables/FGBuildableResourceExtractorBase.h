// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "FactoryGame.h"
#include "FGBuildableFactory.h"
#include "Resources/FGExtractableResourceInterface.h"
#include "Resources/FGResourceDescriptor.h"
#include "FGBuildableResourceExtractorBase.generated.h"

#if UE_BUILD_SHIPPING == 0
#define DEBUG_RESOURCE_EXTRACTORS
#endif

UCLASS()
class FACTORYGAME_API UFGResourceExtractorClipboardRCO : public UFGRemoteCallObject
{
	GENERATED_BODY()
public:
	virtual void GetLifetimeReplicatedProps( TArray< FLifetimeProperty >& OutLifetimeProps ) const override;
	
	UFUNCTION( Server, Reliable )
	void Server_PasteSettings( class AFGBuildableResourceExtractorBase* extractor, AFGCharacterPlayer* player, float overclock, float productionBoost, TSubclassOf<UFGPowerShardDescriptor> overclockingShard, TSubclassOf<UFGPowerShardDescriptor> productionBoostShard );

private:
	UPROPERTY( Replicated, Meta = ( NoAutoJson ) )
	bool mForceNetField_UFGResourceExtractorClipboardRCO = false;

};

UCLASS()
class FACTORYGAME_API UFGResourceExtractorClipboardSettings : public UFGFactoryClipboardSettings
{
	GENERATED_BODY()
public:
	/** The potential we would like to apply */
	UPROPERTY( BlueprintReadWrite )
	float mTargetPotential;

	/** The production boost we would like to apply */
	UPROPERTY( BlueprintReadWrite )
	float mTargetProductionBoost;

	/** The calculated potential we can apply with the shards/crystals we have. Used to simulate UI changes */
	UPROPERTY( BlueprintReadWrite )
	float mReachablePotential;

	/** The calculated production we can apply with the shards we have */
	UPROPERTY( BlueprintReadWrite )
	float mReachableProductionBoost;

	/** Descriptor for the overclocking shard item */
	UPROPERTY( BlueprintReadWrite )
	TSubclassOf<UFGPowerShardDescriptor> mOverclockingShardDescriptor;

	/** Descriptor for the production boost shard item */
	UPROPERTY( BlueprintReadWrite )
	TSubclassOf<UFGPowerShardDescriptor> mProductionBoostShardDescriptor;
};

/**
 * The base class for all resource extractors, i.e. miners and pumps.
 */
UCLASS( Abstract )
class FACTORYGAME_API AFGBuildableResourceExtractorBase : public AFGBuildableFactory
{
	GENERATED_BODY()

public:
	static int GetDebugLevel();
	static void SetDebugLevel( int level );

	/** Decide on what properties to replicate */
	virtual void GetLifetimeReplicatedProps( TArray< FLifetimeProperty >& OutLifetimeProps ) const override;
	virtual void PreReplication( IRepChangedPropertyTracker& ChangedPropertyTracker ) override;

	/** Ctor */
	AFGBuildableResourceExtractorBase();

	// Begin AActor interface
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
	// End AActor interface

	bool DisconnectExtractableResource();

	// Begin Save Interface
	virtual void PostLoadGame_Implementation( int32 saveVersion, int32 gameVersion ) override;
	// End Save Interface

	//~ Begin IFGFactoryClipboardInterface
	virtual bool CanUseFactoryClipboard_Implementation() override { return true; }
	virtual UFGFactoryClipboardSettings* CopySettings_Implementation() override;
	virtual bool PasteSettings_Implementation( UFGFactoryClipboardSettings* factoryClipboard, class AFGPlayerController* player ) override;
	//~ End IFGFactoryClipboardInterface

	/** [DEPRECATED] - Use GetExtractableResource() instead.
	*	Get the resource node this miner is mining from. */
	FORCEINLINE class AFGResourceNode* GetResourceNode() const{ return mExtractResourceNode; }

	/** Get the extractable resource interface this miner is extracting from */
	UFUNCTION( BlueprintPure, Category = "Resource" )
	FORCEINLINE TScriptInterface< IFGExtractableResourceInterface > GetExtractableResource() const { return mExtractableResource; }

	/** Set the extractable resource interface this miner is extracting from */
	void SetExtractableResource( TScriptInterface< IFGExtractableResourceInterface > extractableInterface );

	/** Set this resource node as our current, also claiming it */
	void SetResourceNode( class AFGResourceNode* resourceNode );

	/** Gets particle for mining */
	UFUNCTION( BlueprintPure, Category = "Resources" )
	class UFXSystemAsset* GetMiningParticle();

	 //type names are used to match types for upgrades and such
	FName GetExtractorTypeName() const { return mExtractorTypeName; }

	/** Can this extractor occupy a resource node? */
	bool CanOccupyResource( const TScriptInterface< class IFGExtractableResourceInterface >& resource ) const;

	/** Can this extractor occupy a resource node, given that it is not already occupied? */
	bool IsAllowedOnResource( const TScriptInterface< class IFGExtractableResourceInterface >& resource ) const;
	
protected:
	AActor* GetExtractableResourceActor() const { return mExtractableResource; }

	virtual AActor* TryFindMissingResource();
	virtual void OnExtractableResourceSet();

	UFUNCTION()
	virtual void OnRep_ExtractableResource() { }

protected:
	friend class AFGResourceExtractorHologram;

	/** If set, this extractor type can only be placed on this node type. If None, there is no node-type restriction for this extractor type. */
	UPROPERTY( EditDefaultsOnly, Category = "Extraction" )
	TSubclassOf< class AFGResourceNodeBase > mRestrictToNodeType;

	/** Can we mine solids, liquids, gases or many of the types. */
	UPROPERTY( EditDefaultsOnly, Category = "Extraction" )
	TArray< EResourceForm > mAllowedResourceForms;

	/** Should this extractor only allow extracting from specified resources? 
	* @note - mAllowedResourceForms will still affect placement validation.*/
	UPROPERTY( EditDefaultsOnly, Category = "Extraction" )
	bool mOnlyAllowCertainResources;
	
	/** List of acceptable resources this extractor can mine / pump */
	UPROPERTY( EditDefaultsOnly, Category = "Extraction", meta=( EditCondition="mOnlyAllowCertainResources" ) )
	TArray< TSubclassOf< UFGResourceDescriptor > > mAllowedResources;

	/** Class disqualifier to use when this resource extractor is not placed on a matching resource node ( used in the hologram ) */
	UPROPERTY( EditDefaultsOnly, Category = "Extraction" )
	TSubclassOf< class UFGConstructDisqualifier > mMustPlaceOnResourceDisqualifier;

	/** name used to match types of extractors for compatibility when upgrading */
	UPROPERTY( EditDefaultsOnly, Category = "Extraction" )
	FName mExtractorTypeName = "";

	/** Whether to search for missing resources (usually in the event of rename). At the time of writing is only active on Waterpumps and Fraking buildings */
	UPROPERTY()
	bool mTryFindMissingResource;
	
private:
	/** DEPRECATED - Only used for old save support. Use mExtractableResource instead.
	*   The resource node we want to extract from.
	*/
	UPROPERTY( SaveGame )
	class AFGResourceNode* mExtractResourceNode;

	UPROPERTY( SaveGame, ReplicatedUsing = OnRep_ExtractableResource )
	AActor* mExtractableResource;

};
