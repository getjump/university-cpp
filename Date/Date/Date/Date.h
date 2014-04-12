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
	//������� ������-����� ������ Date
	//����: �������� ������� ������ ������ Date � ������ �������������

public:
	//��������� ������-����� ������ Date

	//����������� �� char*, ������������ ������ "dd.mm.yyyy", ��������� -- �� �������
	Date(char* date);

	//����������� �����������
	Date(const Date& date);

	//����������� �� ���������
	Date();

	//����: ������� �������� � ���������, ��� ���������� �� ��������,
	//� �������������� �� ��������� � �����������
	//��� ����������� ����������� ������������ (� ����� ������ char*)

	//������� ���� � ������� "dd.mm.yyyy" �� �������
	//����: ������������� ����� �������� ����������� ������� ��
	//operator std::string();
	void print();

	inline bool leapYear() const;
	int daysCount() const;

	//�������� ���� ����� ������� ����� � date
	int operator - (const Date& date);

	//�������� �������� � ��������� ����
	Date operator + (int days);
	Date operator - (int days);

	//��������� � ���������
	Date& operator = (const Date& d);
	Date& operator += (int days);
	Date& operator -= (int days);
	Date operator ++ (int);
	Date operator -- (int);
	Date& operator ++ ();
	Date& operator -- ();

	//�������� ���������
	//����: �������� ����� const ����� ������ ���������� ���� ������������ ��� ����������
	//������������� ����� ����������� ����� � ������ ��� �������
	bool operator == (const Date& date) const;
	bool operator != (const Date& date) const;
	bool operator < (const Date& date) const;
	bool operator <= (const Date& date) const;
	bool operator > (const Date& date) const;
	bool operator >= (const Date& date) const;
};
