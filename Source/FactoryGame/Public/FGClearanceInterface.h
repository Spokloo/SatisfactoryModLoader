// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once
#include "FactoryGame.h"
#include "UObject/Interface.h"

#include "FGClearanceData.h"
#include "FGClearanceInterface.generated.h"

/**
 * Interface for actors that interact with the clearance system.
 */
UINTERFACE( Blueprintable )
class FACTORYGAME_API UFGClearanceInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class FACTORYGAME_API IFGClearanceInterface
{
	GENERATED_IINTERFACE_BODY()

	/**
	 * Appends the clearance data for this actor to the specified array.
	 */
	UFUNCTION( BlueprintNativeEvent, Category = "Dismantle" )
	void GetClearanceData( TArray< FFGClearanceData >& out_data ) const;

	/**
	 * Appends any child actors that a clearance overlap with this actor should include in its clearance visualization
	 */
	UFUNCTION( BlueprintNativeEvent, Category= "Clearance" )
	void GetChildClearanceOutlineActors( TArray< AActor* >& out_actors ) const;
};
