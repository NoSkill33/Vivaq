// github.com/NoSkill33
#include "includes.h"

int main(int argc, char* argv[])
{
	string dllname;
	filesystem::path path = filesystem::path(argv[0]);
	string location = path.parent_path().string();

	SetConsoleTitleA(random_string(10).c_str());

	cout << termcolor::white << "Enter dll name: ";
	cin >> dllname;
	
	if (!filesystem::exists(location + "/" + dllname) || dllname.size() < 4 || dllname.substr(dllname.size() - 4) != ".dll")
		cout << "\Make sure is this file exists!";
		Sleep(5000);
		exit(1);
		
	exit(1);
}