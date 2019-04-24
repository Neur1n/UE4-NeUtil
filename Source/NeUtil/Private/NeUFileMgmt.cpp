// Copyright (C) 2019 Neur1n. All Rights Reserved.

#include "NeUFileMgmt.h"

UNeUFileMgmt::UNeUFileMgmt(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer) {
}

// Callable
bool UNeUFileMgmt::SaveStringToFile(FString String, FString FileName) {
  if (FFileHelper::SaveStringToFile(String, *(FPaths::ProjectDir() + FileName))) {
    return UNeUFileMgmt::FileExists(FileName);
  } else {
    return false;
  }
}

bool UNeUFileMgmt::SaveStringArrayToFile(TArray<FString> StringArray, FString FileName) {
  if (FFileHelper::SaveStringArrayToFile(StringArray, *(FPaths::ProjectDir() + FileName))) {
    return UNeUFileMgmt::FileExists(FileName);
  } else {
    return false;
  }
}

bool UNeUFileMgmt::CreateDirectory(FString DirectoryName) {
  IPlatformFile& pf = FPlatformFileManager::Get().GetPlatformFile();

  if (!pf.DirectoryExists(*DirectoryName)) {
    pf.CreateDirectory(*DirectoryName);

    if (!pf.DirectoryExists(*DirectoryName)) {
      return false;
    }
  }
  return true;
}

// Pure
bool UNeUFileMgmt::LoadStringFromFile(FString FileName, FString& String) {
  return FFileHelper::LoadFileToString(String, *(FPaths::ProjectDir() + FileName));
}

bool UNeUFileMgmt::FileExists(FString FileName, int CheckRepeat, float CheckInternal) {
  for (int i = 0; i < CheckRepeat; ++i) {
    if (FPaths::FileExists(FileName)) {
      return true;
    } else {
      FPlatformProcess::Sleep(CheckInternal);
    }
  }
  return false;
}
