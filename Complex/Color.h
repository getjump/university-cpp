#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

struct Color
{
	static void output(string text, WORD bits, WORD defaultColor = 7)
	{
		static HANDLE h = false;
		if (h == false)
			h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, bits);
		cout << text;
		SetConsoleTextAttribute(h, defaultColor);
	}
};