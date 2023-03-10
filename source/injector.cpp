// github.com/NoSkill33
#include "headers/includes.h"

void inject(DWORD processid, const std::string& dllPath)
{

    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processid);
    if (processHandle == NULL)
    {
        return;
    }

    LPVOID dllPathAddress = VirtualAllocEx(processHandle, NULL, dllPath.size() + 1, MEM_COMMIT, PAGE_READWRITE);
    if (dllPathAddress == NULL)
    {
        CloseHandle(processHandle);
        return;
    }

    BOOL writeResult = WriteProcessMemory(processHandle, dllPathAddress, dllPath.c_str(), dllPath.size() + 1, NULL);
    if (!writeResult)
    {
        VirtualFreeEx(processHandle, dllPathAddress, 0, MEM_RELEASE);
        CloseHandle(processHandle);
        return;
    }

    LPVOID loadLibraryAddress = GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
    if (loadLibraryAddress == NULL)
    {
        VirtualFreeEx(processHandle, dllPathAddress, 0, MEM_RELEASE);
        CloseHandle(processHandle);
        return;
    }

    HANDLE threadHandle = CreateRemoteThread(processHandle, NULL, 0, (LPTHREAD_START_ROUTINE)loadLibraryAddress, dllPathAddress, 0, NULL);
    if (threadHandle == NULL)
    {
        VirtualFreeEx(processHandle, dllPathAddress, 0, MEM_RELEASE);
        CloseHandle(processHandle);
        return;
    }

    WaitForSingleObject(threadHandle, INFINITE);

    VirtualFreeEx(processHandle, dllPathAddress, 0, MEM_RELEASE);

    CloseHandle(threadHandle);
    CloseHandle(processHandle);
}

DWORD findprocessid(const std::string& procname)
{
    DWORD processIds[1024], bytesReturned;
    if (!EnumProcesses(processIds, sizeof(processIds), &bytesReturned))
    {
        return 0;
    }

    DWORD count = bytesReturned / sizeof(DWORD);

    for (DWORD i = 0; i < count; i++)
    {
        HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processIds[i]);
        if (processHandle != NULL)
        {
            CHAR imageName[MAX_PATH];
            if (GetProcessImageFileNameA(processHandle, imageName, MAX_PATH) > 0)
            {
                PathStripPathA(imageName);

                if (_stricmp(imageName, procname.c_str()) == 0)
                {
                    CloseHandle(processHandle);
                    return processIds[i];
                }
            }

            CloseHandle(processHandle);
        }
    }

    return 0;
}