// Copyright (C) 2019 Neur1n. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlatformFileManager.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NeUFileMgmt.generated.h"

/**
 * 
 */
UCLASS()
class NEUTIL_API UNeUFileMgmt : public UBlueprintFunctionLibrary {
	GENERATED_UCLASS_BODY()

 public:
  // Callable
  UFUNCTION(BlueprintCallable, Category = "NeUtil", meta = (Keywords = "SaveStringToFile"))
  static bool SaveStringToFile(FString String, FString FileName);

  UFUNCTION(BlueprintCallable, Category = "NeUtil", meta = (Keywords = "SaveStringArrayToFile"))
  static bool SaveStringArrayToFile(TArray<FString> StringArrat, FString FileName);

  UFUNCTION(BlueprintCallable, Category = "NeUtil", meta = (Keywords = "CreateDiretory"))
  static bool CreateDirectory(FString DirectoryName);

  // Pure
  UFUNCTION(BlueprintPure, Category = "NeUtil", meta = (Keywords = "LoadStringFromFile"))
  static bool LoadStringFromFile(FString FileName, FString& String);

  UFUNCTION(BlueprintPure, Category = "NeUtil", meta = (Keywords = "FileExists"))
  static bool FileExists(FString FileName, int CheckRepeat = 5, float CheckInternal = 0.2);
};
