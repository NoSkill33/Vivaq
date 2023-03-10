// github.com/NoSkill33
#pragma once
#include "source/headers/includes.h"

void inject(DWORD processId, const std::string& dllPath);
DWORD findprocessid(const std::string& processName);