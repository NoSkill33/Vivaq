// github.com/NoSkill33
#include "includes.h"

string random_string(const size_t length)
{
	string r;
	static const char bet[] = { "QWERTYUIPOLKJHGFDSAZXCVBNMqwertyuioplkjhgfdsazxcvbnm1234567890!@#$%^&*(" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}