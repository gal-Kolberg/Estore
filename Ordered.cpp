#include "Ordered.h"
#include "Product.h"

bool Ordered::LeftProductToFeedback() // find if there is a product that hasnt been given feedback yet.
{
	int size = (int)m_bought.size();
	for (int i = 0; i < size; i++)
		if (this->m_bought[i]->getFeedback() == false)
			return true;
	return false;
}

void Ordered::setBought(const vector<Product*>& bought)
{
	m_bought = bought;
}

void Ordered::PrintAllBought()
{
	int size = (int)m_bought.size();
	for (int i = 0; i < size; i++)
	{
		cout << "\t\tProduct number #" << i + 1 << endl;
		m_bought[i]->print();
	}
}

void Ordered::CopyAllElements(vector<Product*> other)
{
	int size = (int)other.size();
	for (int i = 0; i < size; i++)
		m_bought.push_back(new Product(*other[i]));
}

const vector<Product*>& Ordered::getBought() const
{
	return m_bought;
}

Ordered::Ordered(vector<Product*> bought)
{
	setBought(bought);
}

Ordered::Ordered(const Ordered& other)
{
	m_bought = other.m_bought;
}

Ordered::~Ordered()
{
	int size = (int)m_bought.size();
	for (int i = 0; i < size; i++)
		delete m_bought[i];
}