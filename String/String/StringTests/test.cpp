#include "..\String.h"
#include <gtest\gtest.h>

TEST(StringTest, CapacityTest)
{
	String s("11");

	EXPECT_EQ(s.capacity(), 4);

	s.reserve(10000);

	EXPECT_EQ(s.capacity(), 10000);
}

TEST(StringTest, PerformanceSubstringTest)
{
	String s("11");
	String s3("11");

	s.reserve(100000);
	
	for (int i = 0; i < 10000; i++)
	{
		s.substr(i * 2 + 1, 0) = s3;
	}

	EXPECT_EQ(strlen(s.buf->string), 20002);
	EXPECT_EQ(s.length(), 20002);
}

TEST(StringTest, PerformanceTest)
{
	String s("1");
	String s2("1");

	s.reserve(1000000);

	for (int i = 0; i < 100000; i++)
	{
		s += s2;
	}
}

TEST(StringTest, InsertTest)
{
	String s("Far Eastern");
	s.insert(4, "1337 ");
	EXPECT_EQ(s, "Far 1337 Eastern");
}

TEST(StringTest, StringRemove)
{
	String s("1122removeme1122");
	s.remove(4, 8);
	EXPECT_EQ(s, "11221122");
}

TEST(StringTest, StringArraySet)
{
	String s("djamalungma");
	s[0] = '2';
	EXPECT_EQ(s[0], '2');
}

TEST(StringTest, StringCharConcatenation)
{
	String s("kilimanjaro");
	char* p = "1";
	s += p;
	EXPECT_EQ(s, "kilimanjaro1");
}

TEST(StringTest, EmptyString)
{
	String empty;

	EXPECT_TRUE(!empty);
}

TEST(StringTest, Comparision)
{
	String s1("228");
	String s2("228");

	EXPECT_TRUE(s1 == s2);
	EXPECT_TRUE(s1 >= s2);
	EXPECT_FALSE(s1 < s2);
	EXPECT_FALSE(s1 > s2);
}

TEST(StringTest, ReferenceCounter)
{
	String s1("228");
	String s2 = s1;
	EXPECT_EQ(s2.rc(), s1.rc());
	EXPECT_EQ(s1.rc(), 2);
	String s3 = s2;
	EXPECT_EQ(s3.rc(), 3);
	s1 = "1337";
	EXPECT_EQ(s1.rc(), 1);
	EXPECT_EQ(s2.rc(), 2);
}

TEST(StringTest, Length)
{
	String s("ololololololo");
	EXPECT_EQ(s.length(), 13);
}

TEST(StringTest, Substr)
{
	String s("oloshka");
	EXPECT_EQ((String)s(0, 3), "olo");
}

TEST(StringTest, SubstrAssignMore)
{
	String s("oloshka");
	s(0, 3) = "228228";
	EXPECT_EQ((String)s(0, 6), "228228");
	EXPECT_EQ(s, "228228shka");
}

TEST(StringTest, SubstrAssignLess)
{
	String s("oloshka");
	s(0, 3) = "2";
	EXPECT_EQ((String)s(0, 3), "2sh");
	EXPECT_EQ(s, "2shka");
}

TEST(StringTest, SubstrAssign)
{
	String s("oloshka");
	s(0, 3) = "228";
	EXPECT_EQ((String)s(0, 3), "228");
	EXPECT_EQ(s, "228shka");
}

TEST(StringTest, ArrayAccess)
{
	String s("dada");
	EXPECT_EQ(s[0], 'd');
	EXPECT_EQ(s[1], 'a');
}

TEST(StringTest, Concatenate)
{
	String s("dada");
	String s2("netnet");

	EXPECT_EQ(s + s2, "dadanetnet");
	s2 += s;
	EXPECT_EQ(s2, "netnetdada");
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}