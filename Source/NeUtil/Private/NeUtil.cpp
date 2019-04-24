// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "NeUtilPrivatePCH.h"


class FNeUtil : public INeUtil {
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FNeUtil, NeUtil)



void FNeUtil::StartupModule() {
}


void FNeUtil::ShutdownModule() {
}
