#include "Buyer.h"
#include "Feedback.h"
#include "Seller.h"
#include "Array.h"

void Seller::PrintForSale()
{
	int size = (int)m_forSale.size();
	if (size != 0) // if there isn't any products
	{
		cout << "All the product that you have put for sale:\n";
		for (int i = 0; i < size; i++)
		{
			cout << "Product #" << i + 1 << ":\n";
			m_forSale[i]->print();
		}
	}
	else
		cout << "No product found in your shop\n\n";
}

void Seller::PrintFeedbacks()
{
	int size_feedbacks = m_feedbacks.getLogicalSize();
	if (size_feedbacks != 0) // if there isn't any products
	{
		cout << "All the feedbacks that you have recived:\n";
		for (int i = 0; i < size_feedbacks; i++)
		{
			cout << "Feedback #" << i + 1 << ":\n\t";
			m_feedbacks[i].print();
			cout << endl;
		}
	}
	else
		cout << "No feedbacks has been given yet\n\n";
}

void Seller::PrintInfo()
{
	this->PrintForSale();
	this->PrintFeedbacks();
}

bool Seller::ProductInCategory(int category_choice)
{ // checks if there are any product in the given category
	int size = (int)m_forSale.size();
	for (int i = 0; i < size; i++)
		if (m_forSale[i]->getCategoty() == category_choice)
			return true;
	return false;
}

void Seller::AddProduct(Product* product)
{ // adding a new product for sale to this seller
	m_forSale.push_back(product);
	cout << "Item added successfully\n\n";
}

void Seller::AddFeedback(const Feedback& feedback)
{ // Adding a new feedback to this seller
	m_feedbacks += feedback;
}

int Seller::PrintByCategory(int CatChoice, int &counter)
{
	int size = (int)m_forSale.size();
	for (int i = 0; i < size; i++) 
		if (m_forSale[i]->getCategoty() == CatChoice) // Only if the category if exists, enter
		{
			cout << "Product #" << ++counter;
			m_forSale[i]->printProductName();
			m_forSale[i]->printPrice();
		}
	return counter;
}

void Seller::setForSale(vector<Product*> forSale)
{
	m_forSale = forSale;
}

void Seller::setFeedback(Array<Feedback> feedback)
{
	m_feedbacks = feedback;
}

vector<Product*>& Seller::getForSale() 
{
	return m_forSale;
}

Array<Feedback>& Seller::getFeedback() 
{
	return m_feedbacks;
}

const Seller & Seller::operator=(const Seller & other)
{
	m_feedbacks = other.m_feedbacks;
	m_forSale = m_forSale;
	return *this;
}

Seller::Seller(Array<Feedback> feedback, vector<Product*> forSale) : m_feedbacks(feedback), m_forSale(forSale)
{
}

Seller::~Seller()
{
	int size = (int)m_forSale.size();
	for (int i = 0; i < size; i++)
		delete m_forSale[i];
}