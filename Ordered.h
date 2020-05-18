#ifndef __ORDERED_H
#define __ORDERED_H

#include "MainHeader.h"

class Product;

class Ordered
{
public:
	bool LeftProductToFeedback();
	void setBought(const vector<Product*>& bought);
	void PrintAllBought();
	void CopyAllElements(vector<Product*> other);
	const vector<Product*>& getBought() const;

	Ordered(vector<Product*> bought = vector<Product*>());
	Ordered(const Ordered& other);
	~Ordered();

private:
	vector<Product*> m_bought;
};
#endif