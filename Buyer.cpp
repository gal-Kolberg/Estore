#include "Feedback.h"
#include "Product.h"
#include "Buyer.h"
#include "Seller.h"
#include "User.h"
#include "Ordered.h"
#include "UserManneger.h"

void Buyer::PrintInfo()
{
	getCart()->PrintAllInterested();
	getCart()->PrintAllSelected();
	this->PrintAllBoughtProducts();
}

int Buyer::PrintForFeedback() // print products to select what product will be given feedback to 
{
	vector<Product*> curr_buy;
	int num_of_product;
	int count = 0;
	int size = (int)m_ordered.size();
	cout << "All the product that you have bought, and haven't gave feedback yet:\n";
	for (int i = 0; i < size; i++)
		if (m_ordered[i]->LeftProductToFeedback() == true)
		{	// only if in this specipic order there is atleast 1 product that hasnt benn given feedback yet.
			cout << "\tPurchase #" << i + 1 << endl;
			num_of_product = (int)m_ordered[i]->getBought().size();
			curr_buy = this->m_ordered[i]->getBought();
			for (int j = 0; j < num_of_product; j++)
				if (curr_buy[j]->getFeedback() == false)
				{
					cout << "\t\tProduct number #" << ++count << endl;
					curr_buy[j]->print();
				}
		}
	return count; // returns the number of product that have beed printed
}

void Buyer::AddPurchase() //  adds a purchase by: moving products arr from the 'selected' to the 'ordered' 
{
	auto selcted_cart = m_cart->getSelected();
	int seleceted_size = (int)selcted_cart.size();
	int order_place = (int)m_ordered.size();
	m_ordered.push_back(new Ordered);
	m_ordered[order_place]->CopyAllElements(selcted_cart);
	for (int i = 0; i < seleceted_size; i++)
		delete selcted_cart[i];
	selcted_cart.clear();
	selcted_cart.shrink_to_fit();
	m_cart->setSelected(selcted_cart);
}

string Buyer::FindProduct(int Choice) 
{	// finds a product according to the useres choice
	int count = 0, num_of_product, size = (int)m_ordered.size();
	vector<Product*> curr_purchase;
	for (int i = 0; i < size; i++)
	{
		num_of_product = (int)m_ordered[i]->getBought().size();
		curr_purchase = this->m_ordered[i]->getBought();
		for (int j = 0; j < num_of_product; j++)
			if (curr_purchase[j]->getFeedback() == false)
			{
				if (count == Choice)
				{
					cout << "Product Found!\n\n";
					curr_purchase[j]->setFeedback(true);
					return curr_purchase[j]->getSellerName();
				}
				count++;
			}
	}
	return "";
}

void Buyer::PrintAllBoughtProducts()
{ // prints all bought products
	int size = (int)m_ordered.size();
	if (size != 0)
	{
		cout << "All the product that you have bought are:\n";
		for (int i = 0; i < size; i++)
		{
			cout << "\tPurchase #" << i + 1 << endl;
			this->getOrdered()[i]->PrintAllBought();
		}
	}
	else
		cout << "No orders found \n\n";
}

bool Buyer::ChooseProduct(UserManneger & UserArr, int index,int &total_of_products)
{ // chooses a prodcut from the interested cart to the selected cart
	int size = (int)m_ordered.size();
	if (UserArr.getUserArr()[index]->IsBuyer() == false)  // check if the user that logged in is a seller or a buyer
	{								// if the user is a seller then return
		cout << "Sellers cannot add feedbacks\n\n";
		return false;
	}
	Buyer *b1 = UserArr.getUserArr()[index]->getBuyer();		// get the buyer that gives the feedback
	if (size == 0)
	{
		cout << "It seems that you havent bought any thing yet, why not start now?\n\n";
		return false;
	}
	for (int i = 0; i < size; i++)
		if (b1->getOrdered()[i]->LeftProductToFeedback() == false)
		{ // enter only if all the product has been given feedback already
			cout << "All the products that you have bought, has been given feedback already\n\n";
			return false;
		}
	cout << "For which Product do you wish to give feedback to?\n\n";
	total_of_products = PrintForFeedback();
	return true;
}

void Buyer::AddFeedback(UserManneger & UserArr, string seller_name, string feedback, Date* date,int index)
{ // add feedback to the seller by a given item
	if (UserArr.getUserArr()[index]->IsBuyer() == false)  // check if the user that logged in is a seller or a buyer
	{								// if the user is a seller then return
		cout << "Sellers cannot add feedbacks\n\n";
		return;
	}
	Buyer *b1 = UserArr.getUserArr()[index]->getBuyer(); // get the buyer that gives the feedback
	int sellerIndex;
	if ((sellerIndex = b1->hasBought(seller_name)) != -1) // checks if the buyer has an item that he bought from the seller and return the seller index in the UserArr 
	{ // hasBought returns '-1' if the seller was not found in the bought item lists
		Seller * s1 = UserArr.getUserArr()[index]->getSeller(); // get the seller
		Feedback *f1 = b1->Givefeedback(feedback, date);
		s1->AddFeedback(*f1); // add the new feedback to the seller
		delete f1;
		cout << "Feedback added sucssefuly\n\n";
	}
	else
		cout << "Feedback was not added\n\n";
}

int Buyer::hasBought(const string sellerName)
{ // checks is the buyer has bought an item from a given seller
	int num_ordered = (int)m_ordered.size();
	vector<Product*> temp; // temp pointer to use class functions
	for (int i = 0; i < num_ordered; i++)
	{ //  checking if the given name is matching any seller name 
		temp = m_ordered[i]->getBought();
		int products_in_order = (int)m_ordered[i]->getBought().size();
		for (int j = 0; j < products_in_order; j++)
			if (sellerName == temp[j]->getSellerName()) 
				return i; // return the index number of the seller in the user array
	}
	cout << "It seems like you haven't bought anything from the seller you have entered, why not start now?\n\n";
	return -1; // -1 no seller by the given name was found 
}

int Buyer::PrintAllCategeryProducts(UserManneger & UserArr, int Catchoice)
{ // prints all products that is in a given category
	int counter = 0;
	int num_of_users = (int)UserArr.getUserArr().size();
	for (int i = 0; i < num_of_users; i++)
		if (UserArr.getUserArr()[i]->IsSeller())
			if (UserArr.getUserArr()[i]->getSeller()->ProductInCategory(Catchoice)) // Checks if there is a product in this category
			{
				cout << UserArr.getUserArr()[i]->getName() << " is selling:\n\n";
				counter = UserArr.getUserArr()[i]->getSeller()->PrintByCategory(Catchoice, counter);
			}
	return counter;
}

Product* Buyer::ReciveProductChosen(UserManneger & UserArr, int Choice, int CatChoice)
{ // gets a number by the user and returns the matching item
	int counter = 1, num_of_items;
	int num_of_users = (int)UserArr.getUserArr().size();
	for (int i = 0; i < num_of_users; i++)
		if (UserArr.getUserArr()[i]->IsSeller() == true)
		{
			Seller *s1 = UserArr.getUserArr()[i]->getSeller();
			num_of_items = (int)s1->getForSale().size();
			for (int j = 0; j < num_of_items; j++)
				if (s1->getForSale()[j]->getCategoty() == CatChoice)
					if (Choice == counter)
						return s1->getForSale()[j];
					else
						counter++;
		}
	return nullptr;
}

Product* Buyer::AddProductToCart(UserManneger &UserArr, int Catchoice, int Choice) 
{  // adds a product to the cart
	Product *p1;
	p1 = ReciveProductChosen(UserArr, Choice, Catchoice);
	if (p1 == nullptr)
	{
		cout << "Somthing went wrong and the product wasn't found please try again\n\n";
		exit(1);
	}
	cout << "Product added to cart sucssefuly\n\n";
	return p1;
}

Feedback* Buyer::Givefeedback(string feedback, Date* date) 
{
	Feedback *f1 = new Feedback(feedback, date);
	return f1;
}

bool Buyer::operator>(const Buyer & right) const
{
	int left_sum = (int)this->getCart()->getPriceOfInterested();
	int right_sum = (int)right.getCart()->getPriceOfInterested();
	return left_sum > right_sum;
}

void Buyer::setCart(Cart* cart)
{
	m_cart = cart;
}

void Buyer::setOrdered(vector<Ordered*> ordered)
{
	m_ordered = ordered;
}

vector<Ordered*> Buyer::getOrdered() const
{
	return m_ordered;
}

Cart* Buyer::getCart() const
{
	return m_cart;
}

const Buyer & Buyer::operator=(const Buyer & other)
{
	m_ordered = other.getOrdered();
	m_cart = other.getCart();
	return *this;
}

Buyer::Buyer(Cart* cart, vector<Ordered*> ordered)
{
	m_cart = new Cart;
	setOrdered(ordered);
}

Buyer::Buyer(const Buyer & other)
{
	m_ordered = other.getOrdered();
	m_cart = other.getCart();
}

Buyer::~Buyer()
{
	int size = (int)m_ordered.size();
	delete m_cart;
	for (int i = 0; i < size; i++)
		delete m_ordered[i];
}
