#include "Product.h"

int Product::SERIAL = 0;

void Product::setFeedback(bool oneOrZero)
{
	m_feedback = oneOrZero;
}

void Product::setName(string name)
{
	m_name = name;
}

void Product::setSellerName(string name)
{
	m_sellerName = name;
}

void Product::setPrice(double price)
{
	m_price = price;
}

void Product::setCategory(eCategory category)
{
	m_category = category;
}

int Product::getSerialNumber() const
{
	return (++this->SERIAL);
}

bool Product::getFeedback() const
{
	return m_feedback;
}

const string Product::getName() const
{
	return m_name;
}

const string Product::getSellerName() const
{
	return m_sellerName;
}

double Product::getPrice() const
{
	return m_price;
}

int Product::getSerialNumber()
{
	return m_serialNumber;
}

int Product::getCategoty() const
{
	return (int)m_category;
}

void Product::print() const
{ // print nicely
	cout << "\t\t\tProduct name is: " << m_name << "\n\t\t\tProduct price: " << m_price <<
		"\n\t\t\tSerial number is: ";
	this->printSerialNumber();
	cout << "\n\t\t\tCategory is: " << Category[(int)m_category] << endl;
}

void Product::printSerialNumber() const
{
	int number_length = 0;
	int num = m_serialNumber;
	while (num != 0)
	{
		number_length++;
		num /= 10;
	}
	for (int i = 0; i < 8 - number_length; i++)
		cout << "0";
	cout << m_serialNumber;
}

void Product::printProductName() const
{
	cout << "\tProduct name is: " << m_name << endl;
}

void Product::printPrice() const
{
	cout << "\t\tProduct price: " << m_price << endl;
}

const Product & Product::operator=(const Product & other)
{
	m_name = other.m_name;
	m_sellerName = other.m_sellerName;
	m_price = other.m_price;
	m_serialNumber = other.getSerialNumber();
	m_category = other.m_category;
	return *this;
}

Product::Product(string name, string sellerName, double price, eCategory category)
{
	setName(name);
	setSellerName(sellerName);
	setPrice(price);
	setCategory(category);
	m_serialNumber = SERIAL++;
}

Product::Product(const Product & other)
{
	*this = other;
}

Product::~Product()
{
}