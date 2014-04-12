#ifndef TEST_H
#define  TEST_H

#include <sstream>
#include <string>
#include <iostream>
#include <windows.h>
#include "Color.h"

namespace getjump {
	namespace Test
	{
		static int tc = 0;
		static int fc = 0;

		static std::stringstream buf;

		template<class T>
		struct Test
		{
			static void assertEqual(T a, T b, std::string s = "")
			{
				if (a == b)
					testPassed(s);
				else
					testNotPassed(s);

#ifdef DEBUG
				std::cout << " " << a << " == " << b << '\n' << '\n';
#endif

				afterTest();
			}

			static void assertEqualEps(T a, T b, double eps, std::string s = "")
			{
				if (abs((double)(a - b)) < eps)
					testPassed(s);
				else
					testNotPassed(s);

#ifdef DEBUG
				std::cout << " " << a << " == " << b << " (+-) " << eps << '\n' << '\n';
#endif

				afterTest();
			}

			static void afterTest()
			{
				tc++;
			}

			static void testPassed(std::string s)
			{
				std::stringstream dat;
				dat << tc + 1;
				if (s != "")
					dat << "(" << s << ")";
				std::cout << "Test #" << dat.str() << " ";
				Color::output("passed", FOREGROUND_GREEN);
				std::cout << '\n';
			}

			static void testNotPassed(std::string s)
			{
				std::stringstream dat;
				dat << tc + 1;
				if (s != "")
					dat << "(" << s << ")";
				std::cout << "Test #" << dat.str() << " ";
				Color::output("not passed", FOREGROUND_RED);
				std::cout << '\n';
				fc++;
			}

			static void completed()
			{
				std::cout << "Valid tests count : ";
				Color::output(std::to_string(tc + 1 - fc), FOREGROUND_GREEN);
				std::cout << " , invalid : ";

				WORD color;
				double c = fc == 0 ? 0 : (tc / fc);
				if (c == 0)
					color = 2;
				else if (c > 3)
					color = 6;
				else if (c < 2)
					color = 4;

				Color::output(std::to_string(fc), color);
				std::cout << '\n';
				std::cout << '\n' << buf.str();
			}
		};
	}
};

#endif // !TEST_H
