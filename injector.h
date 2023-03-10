// github.com/NoSkill33
#pragma once
#include "source/headers/includes.h"

VOID proc_kill();
void inject(DWORD processId, const std::string& dllPath);
DWORD findprocessid(const std::string& processName);