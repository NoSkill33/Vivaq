// github.com/NoSkill33
#include "headers/includes.h"

DWORD proc_find(const wstring& processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!processName.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(processesSnapshot);
	return 0;
}

HANDLE get_handle(int perms = PROCESS_ALL_ACCESS) {
	DWORD pid = proc_find(L"csgo.exe");

	if (!pid)
		return INVALID_HANDLE_VALUE;

	return OpenProcess(perms, FALSE, pid);
}

int main(int argc, char* argv[])
{
	HANDLE csgo_handle = get_handle();

	string procname; // soon
	string dllname;
	filesystem::path path = filesystem::path(argv[0]);
	string location = path.parent_path().string();

	SetConsoleTitleA(random_string(10).c_str());

	//proc_kill();
	ascii();

	cout << termcolor::white << "Enter dll name (eg. base.dll): ";
	cin >> dllname;

	if (!filesystem::exists(location + "/" + dllname) || dllname.size() < 4 || dllname.substr(dllname.size() - 4) != ".dll")
		cout << "\Make sure is this file exists!" << endl;
		Sleep(10000);
		exit(1);

	//WinExec("C:\\Program FIles (x86)\\Steam\\steam.exe -applaunch 730", 0);

	while ((csgo_handle = get_handle(), csgo_handle == INVALID_HANDLE_VALUE))
		Sleep(5000);

	const char* csgo1_mod_path = location.c_str(); + "/" + dllname;
	void* csgo1_module = VirtualAllocEx(csgo_handle, nullptr, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	WriteProcessMemory(csgo_handle, csgo1_module, csgo1_mod_path, sizeof(csgo1_mod_path), nullptr);

	exit(1);
}