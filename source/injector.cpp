// github.com/NoSkill33
#include "headers/includes.h"

bool write_memory(HANDLE hFile, LONG offset, DWORD size, LPCVOID dataBuffer)
{
	DWORD lpNumberOfBytesWritten = 0;
	DWORD retValue = 0;
	DWORD dwError = 0;

	if ((hFile != INVALID_HANDLE_VALUE) && dataBuffer)
	{
		retValue = SetFilePointer(hFile, offset, NULL, FILE_BEGIN);
		dwError = GetLastError();

		if ((retValue == INVALID_SET_FILE_POINTER) && (dwError != NO_ERROR))
		{
			return false;
		}
		else
		{
			if (WriteFile(hFile, dataBuffer, size, &lpNumberOfBytesWritten, 0))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

bool write_memory_new(const CHAR* file, DWORD size, LPCVOID dataBuffer)
{
	HANDLE hFile = CreateFileA(file, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0);

	if (hFile != INVALID_HANDLE_VALUE)
	{
		bool resultValue = write_memory(hFile, 0, size, dataBuffer);
		CloseHandle(hFile);
		return resultValue;
	}
	else
	{
		return false;
	}
}

VOID proc_kill()
{
	HANDLE processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32W processEntry;
	processEntry.dwSize = sizeof(processEntry);

	if (Process32FirstW(processSnapshot, &processEntry)) {
		PCWSTR steamProcesses[] = { L"Steam.exe", L"SteamService.exe", L"steamwebhelper.exe", L"csgo.exe" };
		do {
			for (INT i = 0; i < _countof(steamProcesses); i++) {
				if (!lstrcmpiW(processEntry.szExeFile, steamProcesses[i])) {
					HANDLE processHandle = OpenProcess(PROCESS_TERMINATE, FALSE, processEntry.th32ProcessID);
					if (processHandle) {
						TerminateProcess(processHandle, 0);
						CloseHandle(processHandle);
					}
				}
			}
		} while (Process32NextW(processSnapshot, &processEntry));
	}
	CloseHandle(processSnapshot);
}