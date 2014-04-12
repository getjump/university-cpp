#include <gtest\gtest.h>
#include "..\Date\Date.h"

TEST(DateTest, DateIncrement)
{
	Date d("13.12.2014");
	int c = d.daysCount();
	d++;
	EXPECT_EQ(c + 1, d.daysCount());
}

TEST(DateTest, DateDecrement)
{
	Date d("15.03.2015");
	Date c = --d;
	EXPECT_EQ(c, d);
	EXPECT_EQ(++c, ++d);
}

TEST(DateTest, DateDaysCount)
{
	Date d("01.01.0001");
	EXPECT_EQ(1, d.daysCount());
}

TEST(DateTest, DateComparision)
{
	Date d1("15.03.2015");
	Date d2("16.03.2015");
	EXPECT_TRUE(d1 < d2);
	EXPECT_TRUE(d1 <= d2);
	EXPECT_FALSE(d1 > d2);
	EXPECT_FALSE(d1 == d2);
}

TEST(DateTest, DateMinusDate)
{
	Date d1("17.03.2015");
	Date d2("21.01.2001");

	EXPECT_EQ(5168, d1 - d2);
}

TEST(DateTest, DateLeapYear)
{
	Date d1("17.03.2015");
	EXPECT_FALSE(d1.leapYear());
	d1 -= 1095;
	EXPECT_TRUE(d1.leapYear());
}

TEST(DateTest, DateIncOp)
{
	Date d1("17.03.2015");
	Date d2 = d1;
	for (int i = 0; i < 1000; i++)
		++d2;
	EXPECT_EQ(d2, d2 + 1000);
}

TEST(DateTest, DateSubOp)
{
	Date d("15.03.2015");
	Date d1("17.03.2015");
	Date d2 = d1;
	for (int i = 0; i < 1000; i++)
		--d2;
	EXPECT_EQ(d1 - d2, 1000);
	EXPECT_EQ(d - 30, Date("13.02.2015"));
	EXPECT_EQ(d2, d1 - 1000);
}

TEST(DateTest, DateSup)
{
	Date d1("15.03.2015");
	Date d2("26.06.1996");
	Date d3("27.09.1995");
	EXPECT_EQ(6836, d1 - d2);
	d2 -= 273;
	EXPECT_EQ(d2, d3);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}