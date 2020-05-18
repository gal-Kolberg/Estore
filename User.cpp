#include "User.h"
#include "Adress.h"
#include "Buyer.h"
#include "Seller.h"

int User::UserType() const
{
	if (m_buyer != nullptr && m_seller != nullptr)
		return 3;
	if (m_seller != nullptr)
		return 2;
	else
		return 1;
}

bool User::IsBuyer()
{
	if (m_buyer != nullptr)
		return true;
	return false;
}

bool User::IsSeller()
{
	if (m_seller != nullptr)
		return true;
	return false;
}

void User::setName(string name)
{
	m_name = name;
}

void User::setPassword(string password)
{
	m_password = password;
}

void User::setAdress(Adress *adress)
{
	m_adress = adress;
}

void User::setBuyer(Buyer *buyer)
{
	m_buyer = buyer;
}

void User::setSeller(Seller *seller)
{
	m_seller = seller;
}

const string User::getName() const
{
	return m_name;
}

const string User::getPassword() const
{
	return m_password;
}

Adress* User::getAdress() const
{
	return m_adress;
}

Buyer * User::getBuyer()
{
	return m_buyer;
}

Seller * User::getSeller()
{
	return m_seller;
}


const User & User::operator=(const User & other)
{
	return *this;
}

const User & User::operator=(User && other)
{
	if (this != &other)
	{
		m_name = other.m_name;
		m_password = other.m_password;
		m_adress = other.m_adress;
		other.m_adress = nullptr;
		m_buyer = other.m_buyer;
		other.m_buyer = nullptr;
		m_seller = other.m_seller;
		other.m_seller = nullptr;
	}
	return *this;
}

ostream & operator<<(ostream & os, const User & user)
{
	int type_user = user.UserType();
	if (typeid(os) == typeid(ofstream))
		os << type_user << endl << user.getName() << endl << user.getPassword() << endl << *user.m_adress;
	else
		os <<"The name of the user is: " <<user.m_name << endl << user.m_adress;
	return os;
}

void User::print() const
{
	cout << "Name: " << m_name << "\nAdress:\n";
	m_adress->print();
	cout << endl;
}

User::User(string name, string password, Adress *adress, Buyer* buyer, Seller* seller) : m_name(name) , m_password(password)
{
	setAdress(adress);
	setBuyer(buyer);
	setSeller(seller);
}

User::User(User && other)
{
	*this = move(other);
}

User::User(const User & other)
{
	m_name = other.m_name;
	m_password = other.m_password;
	if (m_adress != nullptr)
		m_adress = new Adress(*other.m_adress);
	else
		m_adress = nullptr;
	if (other.m_buyer != nullptr)
		m_buyer = new Buyer(*other.m_buyer);
	else
		m_buyer = nullptr;
	if (other.m_seller != nullptr)
		m_seller = new Seller(*other.m_seller);
	else
		m_seller = nullptr;
}

User::~User()
{
	delete m_adress;
	delete m_buyer;
	delete m_seller;
}


