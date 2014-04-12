#include <iostream>
#include <iomanip>
#include <vector>

class Date
{
private:
	int day;
	int month;
	int year;
	void normalize();
	std::vector<int> daysInMonth;
	//скрытые данные-члены класса Date
	//прим: добавить скрытых членов класса Date в случае необходимости

public:
	//публичные данные-члены класса Date

	//конструктор из char*, обязательный формат "dd.mm.yyyy", остальные -- по желанию
	Date(char* date);

	//конструктор копирования
	Date(const Date& date);

	//конструктор по умолчанию
	Date();

	//прим: изучить стандарт и проверить, что происходит на практике,
	//с конструкторами по умолчанию и копирования
	//при определении собственого конструктора (в нашем случае char*)

	//вывести дату в формате "dd.mm.yyyy" на консоль
	//прим: факультативно можно заменить предложеную функцию на
	//operator std::string();
	void print();

	inline bool leapYear() const;
	int daysCount() const;

	//разность дней между текущей датой и date
	int operator - (const Date& date);

	//операции сложения и вычитания дней
	Date operator + (int days);
	Date operator - (int days);

	//инкремент и декремент
	Date& operator = (const Date& d);
	Date& operator += (int days);
	Date& operator -= (int days);
	Date operator ++ (int);
	Date operator -- (int);
	Date& operator ++ ();
	Date& operator -- ();

	//операции сравнения
	//прим: ключевое слово const после списка аргументов пока воспринимать как волшебство
	//факультативно можно разобраться зачем и откуда оно взялось
	bool operator == (const Date& date) const;
	bool operator != (const Date& date) const;
	bool operator < (const Date& date) const;
	bool operator <= (const Date& date) const;
	bool operator > (const Date& date) const;
	bool operator >= (const Date& date) const;
};
