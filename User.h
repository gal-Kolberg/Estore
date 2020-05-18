#ifndef __USER_H
#define __USER_H

#include "MainHeader.h"
#include <typeinfo>
#include <fstream>
class Adress;
class Buyer;
class Seller;

class User
{
public:
	int UserType() const;
	bool IsBuyer();
	bool IsSeller();

	void setName(string name);
	void setPassword(string password);
	void setAdress(Adress *adress);
	void setBuyer(Buyer *buyer);
	void setSeller(Seller *seller);

	const string getName() const;
	const string getPassword() const;
	Adress* getAdress() const;
	Buyer* getBuyer();
	Seller* getSeller();

	friend ostream& operator<<(ostream& os, const User& user);
	const User& operator=(const User& other);
	const User& operator=(User&& other);
	virtual void print() const;
	User(string name = string(), string password = string(), Adress *adress = nullptr, Buyer* buyer = nullptr, Seller* seller = nullptr);
	
	User(User&& other);
	User(const User& other);
	~User();

protected:
	string m_name;
	string m_password;
	Adress *m_adress;
	Buyer* m_buyer;
	Seller* m_seller;
};
#endif // !__USER_H
