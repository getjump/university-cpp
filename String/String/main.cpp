#include "String.h"
#include <iostream>

using namespace std;

int main()
{
	String s("11");
	String s3("11");

	s.reserve(1000000);
	
	for (int i = 0; i < 10000; i++)
	{
		s.substr(i * 2 + 1, 0) = s3;
	}
}