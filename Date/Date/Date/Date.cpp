#include "Date.h"
#include <cmath>
#include <ctime>

using namespace std;

Date::Date()
{
	this->day = 1;
	this->year = 0;
	this->month = 1;
	daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}

Date::Date(char* date)
{
	daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	sscanf_s(date, "%d.%d.%d", &this->day, &this->month, &this->year);
	// Validate
	if (this->day < 0 || this->day > 31)
		//throw error
		false;
	if (this->month < 1 || this->month > 12)
		//throw error
		false;
}

void Date::print()
{
	cout << setfill('0') << setw(2) << this->day << "." << setw(2) << this->month << "." << this->year;
}

Date::Date(const Date& date) : day(date.day), month(date.month), year(date.year) 
{
	daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};

inline bool Date::leapYear() const
{
	if (this->year % 4 == 0)
	{
		if (this->year % 100 != 0)
			return true;
		if (this->year % 400 == 0)
			return true;
	}

	return false;
}

int Date::daysCount() const
{
	int m = this->month;
	int d = this->day;
	int y = this->year;
	if (m < 3)
		y--, m += 12;
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

Date& Date::operator = (const Date& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
	return *this;
}

int Date::operator - (const Date& date)
{
	return this->daysCount() - date.daysCount();
}

Date Date::operator + (int days)
{
	Date* n = &(*this);
	n->day += days;
	n->normalize();
	return *n;
}

Date Date::operator - (int days)
{
	Date n = *this;
	n.day -= days;
	n.normalize();
	return n;
}

Date & Date::operator += (int days)
{
	this->day += days;
	this->normalize();
	return *this;
}

Date& Date::operator -= (int days)
{
	this->day -= days;
	this->normalize();
	return *this;
}

Date Date::operator ++ (int)
{
	this->day++;
	this->normalize();
	return *this;
}

Date Date::operator -- (int)
{
	this->day--;
	this->normalize();
	return *this;
}

Date& Date::operator ++ ()
{
	this->day++;
	this->normalize();
	return *this;
}

Date& Date::operator -- ()
{
	this->day--;
	this->normalize();
	return *this;
}

void Date::normalize()
{
	bool ok = true; // Recursion hack
	while (ok)
	{
		int c = (int)floor(this->month / 12);
		if (this->month > 12)
		{
			int m = this->month % 12;
			this->year += c;
			this->month = m == 0 ? 1 : m;
		}
		else if(this->month < 1) 
		{
			this->year -= c == 0 ? 1 : c;
			this->month = 12 - (this->month % 12);
		}

		int dm = this->daysInMonth[this->month - 1];
		if (this->month == 2 && this->leapYear())
			dm += 1;

		if (this->day > dm)
		{
			this->month++;
			this->day -= dm;
			continue;
		} else if (this->day < 1)
		{
			this->month--;
			this->day += this->month - 1 < 0 ? 31 : this->daysInMonth[this->month - 1];
			if (this->leapYear() && this->month == 2)
				this->day += 1;
			continue;
		}

		ok = false;
	}
}

bool Date::operator == (const Date& date) const
{
	return this->daysCount() == date.daysCount();
}

bool Date::operator != (const Date& date) const
{
	return this->daysCount() != date.daysCount();
}

bool Date::operator < (const Date& date) const
{
	return this->daysCount() < date.daysCount();
}

bool Date::operator <= (const Date& date) const
{
	return this->daysCount() <= date.daysCount();
}

bool Date::operator > (const Date& date) const
{
	return this->daysCount() > date.daysCount();
}

bool Date::operator >= (const Date& date) const
{
	return this->daysCount() >= date.daysCount();
}