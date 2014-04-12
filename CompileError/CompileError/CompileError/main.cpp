#include <stdio.h>
#include "multiple_def_2.2.2.a.h"

/* Отсутствие символа при линковке. Pазрешение через extern */
extern void print_Hello_World();

void Example_Error_1()
{
	print_Hello_World();
}

void Example_Error_2()
{
	double Number = 5, Result;
	Result = Do_Unknown_Action_2_2_2_a_1(Number);
}

extern double Do_Unknown_Action_2_2_1_1(double Number);
extern double Do_Unknown_Action_2_2_1_2(double Number);

void Example_Error_3()
{
	double Number = 5, Result;
	Result = Do_Unknown_Action_2_2_1_1(Number);
}

int main()
{
	Example_Error_1();
	Example_Error_2();
	Example_Error_3();
	return 0;
}