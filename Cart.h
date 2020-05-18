#ifndef __CART_H
#define __CART_H

#include "MainHeader.h"

class Product;

class Cart
{
public:
	void DeleteInterested();
	void DeleteSelected();

	void MoveToSelected(int *index_arr, int size);
	void PrintAllInterested();
	void PrintAllSelected();
	void AddToInterested(Product* product);
	void AddToSelected(Product* product);

	void setInterested(vector<Product*> interested);
	void setSelected(vector<Product*> selected);

	double getPriceOfInterested() const;
	const vector<Product*>& getInterested() const;
	const vector<Product*>& getSelected() const;

	const Cart& operator=(const Cart& other);
	Cart(vector<Product*> interested = vector<Product*>(), vector<Product*> selected = vector<Product*>());
	Cart(const Cart& other); 
	~Cart();

private:
	vector<Product*> m_interested;
	vector<Product*> m_selected;
};
#endif // !__CART_H