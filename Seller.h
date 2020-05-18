#ifndef __SELLER_H
#define __SELLER_H

#include "Array.h"
#include "Feedback.h"
#include "Product.h"
#include "User.h"
#include "MainHeader.h"

class Product;
class Feedback;

class Seller : public User
{
public:
	void PrintForSale();
	void PrintFeedbacks();
	void PrintInfo();
	bool ProductInCategory(int category_choice);
	void AddProduct(Product* product);
	void AddFeedback(const Feedback& feedback);
	int PrintByCategory(int CatChoice, int &counter);
	void setForSale(vector<Product*> forSale);
	void setFeedback(Array<Feedback> feedback);
	
	vector<Product*>& getForSale();
	Array<Feedback>& getFeedback();

	const Seller& operator=(const Seller& other);
	Seller(Array<Feedback> feedback = Array<Feedback>(), vector<Product*> forSale = vector<Product*>());
	~Seller();

private:
	vector<Product*> m_forSale;
	Array<Feedback> m_feedbacks;
};
#endif // !__SELLER_H
