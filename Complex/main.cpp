#define DEBUG
#define EOL '\n'
#define printLine(x) (cout << x << EOL)

#include <iostream>
#include "complex.h"
#include "Test.h"

using namespace std;
using namespace getjump::Test;
using namespace getjump::Complex;
using namespace getjump::Complex::literals;

int main()
{
	Complex<int> c = ii * ii * ii;
	Complex<double> d = c; 
	d = d.rotation(-90.0);
	Complex<double> l = d.conjugate();
	Complex<double> o = l - d;
	Complex<int> a = 3 + 1 * ii;

	Complex<double> da = a / c;

	Test<bool>::assertEqual(true, false, "Fictive Test Data(test purpose)");
	Test<Complex<double>>::assertEqualEps(o, Complex<double>(0, -3.9), 0.1, "Fictive Test Data(test purpose)");
	Test<int>::assertEqual(Complex<int>(3, 1).getReal(), 3, "Get Real");
	Test<int>::assertEqual(Complex<int>(0, 1).getImaginary(), 1, "Get Imaginary");
	Test<Complex<int>>::assertEqual(a, Complex<int>(3, 1), "Overloaded initialization");
	Test<Complex<int>>::assertEqual(c, Complex<int>(0, -1), "Multiplication of ImaginaryUnit");
	Test<Complex<double>>::assertEqualEps(o, Complex<double>(0, -0.89), 0.1, "Binary Minus");
	Test<Complex<double>>::assertEqualEps(d, Complex<double>(-0.89, 0.44), 0.1, "Type conversion and rotation");
	Test<Complex<double>>::assertEqualEps(l, Complex<double>(-0.89, -0.44), 0.1, "Conjugate");
	Test<double>::assertEqualEps(abs(o.arg()), 1.57, 0.1, "Arg");
	Test<double>::assertEqualEps(abs(o.abs()), 0.89, 0.1, "Abs");
	Test<bool>::assertEqual(Complex<int>(3, 1) == Complex<int>(3, 1), true, "Equality operator");
	Test<Complex<double>>::assertEqual(da, Complex<double>(-1, 3), "Division");

	Test<void*>::completed();

	system("PAUSE");
}