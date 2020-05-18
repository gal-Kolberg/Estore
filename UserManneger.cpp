#include "Adress.h"
#include "Seller.h"
#include "Buyer.h"
#include "User.h"
#include "UserManneger.h"

void UserManneger::PrintAllMultiUsers()
{
	int size = (int)m_userArr.size();
	for (int i = 0; i < size; i++)
		if (m_userArr[i]->IsBuyer() && m_userArr[i]->IsSeller())
			m_userArr[i]->print();
}

void UserManneger::PrintAllBuyersByName()
{
	int size = (int)m_userArr.size();
	for (int i = 0; i < size; i++)
	{
		if (m_userArr[i]->IsBuyer())
		{
			if(i != size - 1)
				cout << m_userArr[i]->getName() << ", ";
			else
				cout << m_userArr[i]->getName() << "\n\n";
		}
	}
}

void UserManneger::PrintAllBuyers()
{
	int size = (int)m_userArr.size();
	bool buyer = false;
	for (int i = 0; i < size; i++)
		if (m_userArr[i]->IsBuyer() == true)
		{
			cout << "The buyer ";
			m_userArr[i]->print();
			m_userArr[i]->getBuyer()->PrintInfo();
			buyer = true;
		}
	if (buyer == false)
		cout << "No Buyers was found\n\n";
}

void UserManneger::PrintAllSellers()
{
	int size = (int)m_userArr.size();
	bool seller = false;
	for (int i = 0; i < size; i++)
		if (m_userArr[i]->IsSeller() == true)
		{
			cout << "The seller ";
			m_userArr[i]->print();
			m_userArr[i]->getSeller()->PrintInfo();
			seller = true;
		}
	if (seller == false)
		cout << "No sellers was found\n\n";
}

void UserManneger::PrintAllProductByName(string product_name)
{
	vector<Product*> temp;
	int num_of_products, counter = 0, size = (int)m_userArr.size();
	for (int i = 0; i < size; i++) // Run on all the users
		if (m_userArr[i]->IsSeller() == true)
		{  // only if it's a seller 
			temp = m_userArr[i]->getSeller()->getForSale();
			num_of_products = (int)m_userArr[i]->getSeller()->getForSale().size();
			for (int j = 0; j < num_of_products; j++)
				if (temp[j]->getName() == product_name)
				{
					cout << temp[j]->getSellerName() << " is selling:\n";
					temp[j]->print();
					cout << endl;
					counter++;
				}
		}
	if (counter == 0)
		cout << "No product was found\n\n";
}

void UserManneger::WriteToFile(string file_name)
{
	int size = (int)m_userArr.size();
	ofstream outFile(file_name, ios::trunc);
	outFile << size << endl;
	for (int i = 0; i < size; i++)
		outFile << *m_userArr[i];
}

void UserManneger::ReadFromFile(string file_name)
{
	ifstream in_file;
	in_file.open(file_name, ios::in);
	string size, user_type, user_name, user_pass, user_city, user_street, user_house;
	Adress *user_adress;
	getline(in_file, size);
	if (size == "")
	{
		in_file.close();
		return;
	}
	int num_elem = stoi(size);
	int indicator, house_num;
	for (int i = 0; i < num_elem; i++)
	{
		getline(in_file, user_type);
		getline(in_file, user_name);
		getline(in_file, user_pass);
		getline(in_file, user_city);
		getline(in_file, user_street);
		getline(in_file, user_house);
		indicator = stoi(user_type);
		house_num = stoi(user_house);
		user_adress = new Adress(user_city, user_street, house_num);
		this->AddUser(indicator, user_name, user_pass, user_adress,true);
	}
	in_file.close();
}

bool UserManneger::categoryExists(int catChoice)
{ // checks if there are any product in the given category
	int size = (int)m_userArr.size();
	for (int i = 0; i < size; i++)
		if (m_userArr[i]->IsSeller())
			if (m_userArr[i]->getSeller()->ProductInCategory(catChoice) == true)
				return true;
	return false;
}

const UserManneger& UserManneger::AddUser(int Indicator, string user_name, string user_password, Adress* address, bool FromFile)
{ // Adding an new user	
	if (Indicator == 2) // 2 == seller
	{
		User* user_seller = new User(user_name, user_password, address, nullptr, new Seller);
		this->m_userArr.push_back(user_seller);
		if(FromFile == false)
			cout << "Seller added successfully\n\n";
	}
	else if(Indicator == 1) // 1 == buyer
	{
		User* user_buyer = new User(user_name, user_password, address, new Buyer, nullptr);
		this->m_userArr.push_back(user_buyer);
		if (FromFile == false)
			cout << "Buyer added successfully\n\n";
	}
	else // the new user is a buyer and a seller
	{
		User *user_multi = new User(user_name, user_password, address, new Buyer, new Seller);
		this->m_userArr.push_back(user_multi);
		if (FromFile == false)
			cout << "User added successfully\n\n";
	}
	return *this;
}

int UserManneger::ValidateName(string name)
{ // checks if the given name is exists
	int size = (int)m_userArr.size();
	for (int i = 0; i < size; i++)
		if (m_userArr[i]->getName() == name)
			return i;
	return -1;
}

bool UserManneger::ValidatePassword(const string password, int index)
{ // checks if the given password match the given index that indicate the user
	if (m_userArr[index]->getPassword() == password)
		return true;
	return false;
}

void UserManneger::AddProdctToIntereseted(int index,Product* product)
{
	Product *p_copy = new Product(*product);
	m_userArr[index]->getBuyer()->getCart()->AddToInterested(p_copy);
}

void UserManneger::AddProductToSeller(int index,string item_name, double price, int category)
{
	Seller * s1 = m_userArr[index]->getSeller();
	string n1= m_userArr[index]->getName();
	Product *p1 = new Product(item_name, n1, price,(Product::eCategory)category);
	auto for_sale = s1->getForSale();
	for_sale.push_back(p1);
	s1->setForSale(for_sale);
	cout << "Item added successfully\n\n";
}

const int UserManneger::Login(string name, string password)
{ // for almost every action in the menu, it's verify the user
	int index;
	index = ValidateName(name);
	if (index != -1)
		if (ValidatePassword(password, index))
		{
			cout << "Login successful\n\n";
			return index;
		}
		else
				cout << "Wrong password, try again\n\n";
		else
			cout << "Wrong username, try again\n\n";
	return -1;
}

Seller * UserManneger::FindSeller(const string name)
{ // finds the seller with the given name
	int size = (int)m_userArr.size();
	for (int i = 0; i < size; i++)
		if (m_userArr[i]->getName() == name)
			return m_userArr[i]->getSeller();
	return nullptr;
}

bool UserManneger::ValidateNameBool(string name)
{
	int size = (int)m_userArr.size();
	for (int i = 0; i < size; i++)
		if (m_userArr[i]->getName() == name)
			return true;
	return false;
}

void UserManneger::setUserArr(vector<User*> userArr)
{
	m_userArr = userArr;
}

const UserManneger& UserManneger::operator+=(const User & user)
{
	Adress *adress = new Adress(*user.getAdress());
	User *u1 = new User(user.getName(), user.getPassword(), adress, new Buyer, new Seller);
	m_userArr.push_back(u1);
	delete u1;
	return *this;
}

const UserManneger& UserManneger::operator+=(const Buyer& buyer)
{
	Adress *adress = new Adress(*buyer.getAdress());
	m_userArr.push_back(new User(buyer.getName(), buyer.getPassword(),adress, new Buyer, nullptr));
	return *this;
}

const UserManneger& UserManneger::operator+=(const Seller & seller)
{
	Adress *adress = new Adress(*seller.getAdress());
	m_userArr.push_back(new User(seller.getName(), seller.getPassword(), adress, nullptr,new Seller));
	return *this;
}

Buyer * UserManneger::getBuyerByName(string name)
{
	int size = (int)m_userArr.size();
	for (int i = 0; i < size; i++)
		if (m_userArr[i]->getName() == name)
			return m_userArr[i]->getBuyer();
	return nullptr;
}

vector<User*>& UserManneger::getUserArr()
{
	return m_userArr;
}

UserManneger::UserManneger(vector<User*> userArr) // constructor
{
	setUserArr(userArr);
}

UserManneger::~UserManneger() // destractor
{
	int size = (int)m_userArr.size();
	for (int i = 0; i < size; i++)
		delete m_userArr[i];
}