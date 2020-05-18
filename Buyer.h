#ifndef __BUYER_H
#define __BUYER_H
#include "Ordered.h"
#include "Cart.h"
#include "User.h"

class Date;
class Product;
class Feedback;
class UserManneger;
class Ordered;

class Buyer : public User
{
public:
	void PrintInfo();
	int PrintForFeedback();
	void AddPurchase();
	string FindProduct(int Choice);
	void PrintAllBoughtProducts();
	bool ChooseProduct(UserManneger &UserArr, int index, int &total_of_products);
	void AddFeedback(UserManneger &UserArr,string seller_name,string feedback, Date* date,int index);
	int hasBought(const string sellerName);
	int PrintAllCategeryProducts(UserManneger &UserArr, int Catchoice);
	Product *ReciveProductChosen(UserManneger & UserArr, int Choice, int CatChoice);
	Product* AddProductToCart(UserManneger &UserArr,int Catchoice,int Choice);
	Feedback* Givefeedback(string feedback, Date* date);

	bool operator>(const Buyer &right) const;

	void setCart(Cart* cart);
	void setOrdered(vector<Ordered*> ordered);

	vector<Ordered*> getOrdered() const;
	Cart* getCart() const;
	const Buyer& operator=(const Buyer& other);

	Buyer(Cart* cart = nullptr, vector<Ordered*> ordered = vector<Ordered*>());
	Buyer(const Buyer& other);
	~Buyer();

private:
	Cart* m_cart;
	vector<Ordered*> m_ordered;
};
#endif // !__BUYER_H