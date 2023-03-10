// github.com/NoSkill33
#include "headers/includes.h"

int main(int argc, char* argv[])
{
	string procname;
	string dllname;
	filesystem::path path = filesystem::path(argv[0]);
	string location = path.parent_path().string();

	SetConsoleTitleA(random_string(10).c_str());

	//proc_kill();
	ascii();

	cout << termcolor::white << "Enter process name (eg. csgo.exe): ";
	cin >> procname;

	cout << termcolor::white << "Enter dll name (eg. base.dll): ";
	cin >> dllname;

	if (!filesystem::exists(location + "\\" + dllname) || dllname.size() < 4 || dllname.substr(dllname.size() - 4) != ".dll") {
		cout << "Make sure is this file exists! (" << location + "\\" + dllname << ")" << endl;
		Sleep(10000);
		return 0;
	}

	//WinExec("C:\\Program FIles (x86)\\Steam\\steam.exe -applaunch 730", 0);

	DWORD processid = findprocessid(procname);

	inject(processid, dllname);

	std::cout << "injected?" << std::endl;

	return 0;
}