double Do_Unknown_Action_2_2_1_1(double Number);
//double Arifmetic(double Number);
static double Arifmetic(double Number);

/* 2 ���-����� � ���������� ����� static*/
/* ���� 1 */

double Do_Unknown_Action_2_2_1_1(double Number)
{
	return Arifmetic(Number);
}

//double Arifmetic(double Number)
static double Arifmetic(double Number)
{
	return (--Number);
}