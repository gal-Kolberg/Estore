#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "MainHeader.h"

class Product
{
public:
	static int SERIAL;
	enum eCategory { KIDS, ELECTRONICS, OFFICE, CLOTHING };
	static const char* Category[];

	void setFeedback(bool oneOrZero);
	void setName(string name);
	void setSellerName(string name);
	void setPrice(double price);
	void setCategory(eCategory category);

	int getSerialNumber() const;
	bool getFeedback() const;
	const string getName() const;
	const string getSellerName() const;
	double getPrice() const;
	int getSerialNumber();
	int getCategoty() const;


	void print() const;
	void printSerialNumber() const;
	void printProductName() const;
	void printPrice() const;

	const Product& operator=(const Product & other);

	Product(string name = string(), string sellerName = string(), double price = 0 , eCategory category = (eCategory)0);
	Product(const Product& other);
	~Product();

private:
	string m_name;
	string m_sellerName;
	double m_price;
	int m_serialNumber;
	eCategory m_category;
	bool m_feedback = 0; // 0 - not yet given, 1 - given
};
#endif