#include "Date.h"

int main()
{
	Date d2("01.01.2013");

	Date d1("26.06.1996");

	auto c = d1 - 1;

	c.print();

	system("pause");
}