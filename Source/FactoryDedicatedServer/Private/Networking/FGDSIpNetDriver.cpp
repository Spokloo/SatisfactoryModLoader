// This file has been automatically generated by the Unreal Header Implementation tool

#include "Networking/FGDSIpNetDriver.h"

bool UFGDSIpNetDriver::InitBase(bool bInitAsClient, FNetworkNotify* InNotify, const FURL& URL, bool bReuseAddressAndPort, FString& Error){ return bool(); }
FUniqueSocket UFGDSIpNetDriver::CreateAndBindSocket(TSharedRef<FInternetAddr> BindAddr, int32 Port, bool bReuseAddressAndPort, int32 DesiredRecvSize, int32 DesiredSendSize, FString& Error){ return FUniqueSocket(); }
void UFGDSIpNetDriver::SetWorld(UWorld* InWorld){ }
bool UFGDSIpNetDriver::ReclaimCurrentServerSocket(TSharedPtr<FSocket>& ServerSocket){ return false; }
FUniqueSocket UFGDSIpNetDriver::TryReclaimNativeSocket(FSocket* Socket){ return FUniqueSocket(); }
