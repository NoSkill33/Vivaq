// github.com/NoSkill33
#include "headers/includes.h"

VOID ascii()
{
	cout << " _    ___                  " << endl;
	cout << "| |  / (_)   ______ _____ _" << endl;
	cout << "| | / / / | / / __ `/ __ `/" << endl;
	cout << "| |/ / /| |/ / /_/ / /_/ / " << endl;
	cout << "|___/_/ |___/ __,_/ __, /  " << endl;
	cout << "                     /_/   \n" << endl;
}

string random_string(const size_t length)
{
	string r;
	static const char bet[] = { "QWERTYUIPOLKJHGFDSAZXCVBNMqwertyuioplkjhgfdsazxcvbnm1234567890!@#$%^&*(" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}