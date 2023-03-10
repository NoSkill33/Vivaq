// github.com/NoSkill33
#pragma once
#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <Shlwapi.h>

#include "random.h"
#include "termcolor.h"
#include "main.h"
#include "../injector.h"

#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "Shlwapi.lib")

using namespace std;