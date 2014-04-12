#ifndef Multiple_def_1_H
#define Multiple_def_1_H

/* Определение в header-файле. Pазрешение через static */

static double Do_Unknown_Action_2_2_2_a_1(double Number);
static double Arifmetic(double Number);

//double Arifmetic(double Number)
static double Arifmetic(double Number)
{
	return (--Number);
}

static double Do_Unknown_Action_2_2_2_a_1(double Number)
{
	return Arifmetic(Number);
}

#endif 