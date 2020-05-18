#include "Date.h"

bool Date::setDate(const int day, const int month, const int year)
{
	if (setDay(day) && setMonth(month) && setYear(year))
		return true;
	else 
	{
		cout << "One of the Inputs was an invalid input, Please try again\n\n";
		return false;
	}
}

void Date::PrintDate()
{
	(m_day < 10 ? cout << "0" << m_day : cout << m_day);
	cout << "/";
	(m_month < 10 ? cout << "0" << m_month : cout << m_month);
	cout << "/" << m_year;
}

Date::Date(const Date & other)
{
	m_day = other.m_day;
	m_month = other.m_month;
	m_year = other.m_year;
}

const Date & Date::operator=(Date & other)
{
	m_day = other.m_day;
	m_month = other.m_month;
	m_year = other.m_year;
	return *this;
}

Date::Date(int day, int month, int year)
{
	setDate(day, month, year);
}

Date::~Date()
{
}

int Date::getDay()
{
	return m_day;
}

int Date::getMonth()
{
	return m_month;
}

int Date::getYear()
{
	return m_year;
}

bool Date::setDay(int day)
{
	if (day > 0 && day < 32) {
		m_day = day;
		return true;
	}
	else 
		return false;
}

bool Date::setYear(int year)
{
	if (year >= 0)
	{
		m_year = year;
		return true;
	}
	else 
		return false;
}

bool Date::setMonth(int month)
{
	if (month > 0 && month < 13)
	{
		m_month = month;
		return true;
	}
	else 
		return false;
}

ostream & operator<<(ostream & os, const Date & date)
{
	os << date.m_day << "/" << date.m_month << "/" << date.m_year << "\n\n";
	return os;
}
