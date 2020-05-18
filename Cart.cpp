#include "Date.h"
#include "Cart.h"
#include "Product.h"

void Cart::DeleteInterested()
{
	m_interested.clear();
}

void Cart::DeleteSelected()
{
	m_selected.clear();
}

void Cart::MoveToSelected(int *index_arr, int size)
{ // moves from 'interested' cart to 'selected' cart
	vector<Product*>::iterator itr = m_interested.begin();
	for (int i = 0; i < size; i++) // move choosen product to selectedArr 
		this->AddToSelected(new Product(*m_interested[index_arr[i] - 1])); // takes every product from the selected items to the 'selected' cart
	for (int i = 0; i < size; i++)
	{
		delete m_interested[index_arr[i] - 1]; // delete in interested car
		m_interested[index_arr[i] - 1] = m_interested.back();
		m_interested.pop_back(); // delete in interested cart
	}
	cout << "All the choosen product are ready to purchase\n\n";
}

void Cart::PrintAllInterested()
{
	int size = (int)m_interested.size();
	if (size != 0)
	{
		cout << "All the products that you showed interest in, are:\n";
		for (int i = 0; i < size; i++)
		{
			cout << "\tProduct number #" << i + 1 << endl;
			m_interested[i]->print();
		}
	}
	else
		cout << "No product found in your Interesed cart\n\n";
}

void Cart::PrintAllSelected()
{
	int size = (int)m_selected.size();
	if ( size != 0)
	{
		cout << "All the products that you have selected are:\n";
		for (int i = 0; i < size; i++)
		{
			cout << "Product number #" << i + 1 << endl;
			m_selected[i]->print();
		}
	}
	else
		cout << "No product found in your Selected cart\n\n";
}

void Cart::AddToInterested(Product* product)
{
	m_interested.push_back(product);
}

void Cart::AddToSelected(Product* product)
{
	m_selected.push_back(product);
}

void Cart::setInterested(vector<Product*> interested)
{
	m_interested = interested;
}

void Cart::setSelected(vector<Product*> selected)
{
	m_selected = selected;
}

double Cart::getPriceOfInterested() const
{
	double sum = 0;
	int size = (int)m_interested.size();
	for (int i = 0; i < size; i++)
		sum += m_interested[i]->getPrice();
	return sum;
}

const vector<Product*>& Cart::getInterested() const
{
	return m_interested;
}

const vector<Product*>& Cart::getSelected() const
{
	return m_selected;
}

const Cart & Cart::operator=(const Cart & other)
{
	m_interested = other.m_interested;
	m_selected = other.m_selected;
	return *this;
}

Cart::Cart(vector<Product*> interested, vector<Product*> selected)
{
	setInterested(interested);
	setSelected(selected);
}

Cart::Cart(const Cart & other)
{
	m_interested = other.m_interested;
	m_selected = other.m_selected;
}

Cart::~Cart()
{
	int sizeI = (int)m_interested.size();
	int sizeS = (int)m_selected.size();
	for (int i = 0; i < sizeI; i++)
		delete m_interested[i];
	for (int i = 0; i < sizeS; i++)
		delete m_selected[i];
}