#include "Adress.h"

void Adress::setCity(string city)
{
	m_city = city;
}

void Adress::setStreet(string street)
{
	m_street = street;
}

bool Adress::setHouseNumber(int houseNumber)
{
	if (houseNumber >= 0) {
		m_houseNumber = houseNumber;
		return true;
	}
	else
	{
		cout << "House number can not be a negative number, please try again\n\n";
		return false;
	}
}

const string Adress::getCity() const
{
	return m_city;
}

const string Adress::getStreet() const
{
	return m_street;
}

int Adress::getHouseNumber() const
{
	return m_houseNumber;
}

void Adress::print() const
{
	cout << "City: " << m_city << "\nStreet: " << m_street << "\nHouse #" << m_houseNumber << endl;
}

Adress::Adress(string city, string street, int houseNumber)
{
	setCity(city);
	setStreet(street);
	setHouseNumber(houseNumber);
}

Adress::Adress(const Adress & other)
{
	m_city = other.m_city;
	m_street = other.m_street;
	m_houseNumber = other.m_houseNumber;
}

Adress::~Adress()
{
}

ostream & operator<<(ostream & os, const Adress & address)
{
	if (typeid(os) == typeid(ofstream))
		os << address.m_city << "\n" << address.m_street << "\n" << address.m_houseNumber << "\n";
	else
		os << "City: " << address.m_city << "\nStreet: " << address.m_street << "\nHouse number: " << address.m_houseNumber << "\n\n";
	return os;

}
