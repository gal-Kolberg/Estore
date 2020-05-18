#ifndef __ADRESS_H
#define __ADRESS_H

#include "MainHeader.h"

class Adress
{
public:
	void setCity(string city);
	void setStreet(string street);
	bool setHouseNumber(int houseNumber);

	const string getCity() const;
	const string getStreet() const;
	int getHouseNumber() const;

	void print() const;

	friend ostream& operator<<(ostream&  os, const Adress &address);

	Adress(string city = string(), string street = string(), int houseNumber = 0);
	Adress(const Adress& other);
	~Adress();

private:
	string m_city;
	string m_street;
	int m_houseNumber;
};
#endif // !__ADRESS_H