#ifndef __USERMANNEGER_H
#define __USERMANNEGER_H

#include "MainHeader.h"
#include "Seller.h"
#include "Buyer.h"

class Buyer;
class User;

class UserManneger 
{
public:
	void PrintAllMultiUsers();
	void PrintAllBuyersByName();
	void PrintAllBuyers();
	void PrintAllSellers();
	void PrintAllProductByName(string product_name);

	void WriteToFile(string file_name);
	void ReadFromFile(string file_name);

	void AddProdctToIntereseted(int index, Product* product);
	void AddProductToSeller(int index, string item_name, double price, int category);
	const int Login(string name, string password);
	int ValidateName(string name);
	bool ValidatePassword(const string password, int index);
	bool categoryExists(int catChoice);
	Buyer* getBuyerByName(string name);
	Seller* FindSeller(const string name);
	bool ValidateNameBool(string name);

	void setUserArr(vector<User*> userArr);

	const UserManneger& AddUser(int Indicator, string user_name, string user_password, Adress* address,bool FromFile);
	const UserManneger& operator+=(const User & User);
	const UserManneger& operator+=(const Buyer &buyer);
	const UserManneger& operator+=(const Seller &seller);

	vector<User*>& getUserArr();
	UserManneger(vector<User*> userArr = vector<User*>());
	~UserManneger();

private:
	vector<User*> m_userArr;
};
#endif // !__USERMANNEGER_H
