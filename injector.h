// github.com/NoSkill33
#pragma once
#include "source/headers/includes.h"

bool write_memory(HANDLE hFile, LONG offset, DWORD size, LPCVOID dataBuffer);
bool write_memory_new(const CHAR* file, DWORD size, LPCVOID dataBuffer);
VOID proc_kill();