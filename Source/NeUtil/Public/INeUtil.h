// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"


/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules 
 * within this plugin.
 */
class INeUtil : public IModuleInterface {
 public:
	static inline INeUtil& Get() {
		return FModuleManager::LoadModuleChecked<INeUtil>("NeUtil");
	}

	static inline bool IsAvailable() {
		return FModuleManager::Get().IsModuleLoaded("NeUtil");
	}
};

