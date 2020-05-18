#ifndef __DATE_H
#define __DATE_H

#include "MainHeader.h"

class Date
{
public:
	Date(int day = 1, int month = 1, int year = 1);
	~Date();
	int getDay();
	int getMonth();
	int getYear();
	bool setDate(const int day, const int month, const int year);
	void PrintDate();
	Date(const Date& other);
	const Date& operator=(Date & other);
	friend ostream& operator<<(ostream&  os, const Date &date);

	bool setDay(int day);
	bool setYear(int year);
	bool setMonth(int month);

private:
	int m_day;
	int m_month;
	int m_year;
};
#endif // !__DATE.H