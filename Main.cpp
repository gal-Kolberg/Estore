/*
Daniel Shaanan
313622268
Gal Kolberg
206097925
Teacher: Keren Kalif, sunday
Group A
*/
#include "Adress.h"
#include "Product.h"
#include "Buyer.h"
#include "Seller.h"
#include "User.h"
#include "MainHeader.h"
#include "UserManneger.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

const char* Product::Category[] = { "Kids", "Electronics" , "Office", "Clothing" };

void UserChoice(int Userinput, UserManneger& UserArr)
{
	switch (Userinput)
	{
	case 1:	// add a new buyer
	{
		CaseAddSellerBuyerFunction(UserArr, Userinput);
		return;
	}
	case 2: // add a new seller
	{
		CaseAddSellerBuyerFunction(UserArr, Userinput);
		return;
	}
	case 3: // add new product
	{
		Case3Function(UserArr, Userinput);
		return;
	}
	case 4:
	{ // Add feedback
		Case4Function(UserArr, Userinput);
		return;
	}
	case 5:
	{ // Add a product to cart (interested cart)
		Case5Function(UserArr, Userinput);
		return;
	}
	case 6:
	{ // Add a product to cart (selected cart)
		Case6Function(UserArr, Userinput);
		return;
	}
	case 7:
	{ // execute the purchase, i.e moving from 'Selected' cart to 'bought' history
		Case7Function(UserArr, Userinput);
		return;
	}
	case 8:
	{ // Prints all the buyers
		UserArr.PrintAllBuyers();
		return;
	}
	case 9:
	{ // Prints all the sellers
		UserArr.PrintAllSellers();
		return;
	}
	case 10:
	{ // search product by name
		cin.ignore();
		string product_name = ReciveProductName(); // getting input from user
		UserArr.PrintAllProductByName(product_name);
		return;
	}
	case 11:
	{ // To compere between two buyers with the operator >
		Case11Function(UserArr);
		return;
	}
	case 12: 
	{ // Add buyer by operator +=
		Case12Function(UserArr);
		return;
	}
	case 13: 
	{ // Add seller by operator +=
		Case13Function(UserArr);
		return;
	}
	case 14:
	{ // To add a user that is a seller and a buyer
		Case14Function(UserArr, Userinput);
		return;
	}
	case 15:
	{ // Prints all the users that are sellers and buyers
		UserArr.PrintAllMultiUsers();
		return;
	}
	case 16:
	{ // Operator << for specific seller, prints it's feedback and dates
		Case16Function(UserArr, Userinput);
		return;
	}
	case 17:
	{
		cout << "Thank you for your use\n";
		UserArr.WriteToFile("UserData.txt");
		return;
	}
	default:
	{
		cout << "You have selceted an invalid choice, try again\n\n";
		return;
	}
	}
}

int main()
{
	{
		int UserInput;
		UserManneger UserArr;
		UserArr.ReadFromFile("UserData.txt");
		do
		{
			cout << "To add a new buyer, enter 1\n"
				<< "To add a new seller, enter 2\n"
				<< "To add a new item for sale, enter 3\n"
				<< "To add a new Feedback, enter 4\n"
				<< "To add a new product to your cart, enter 5\n"
				<< "To choose products from your cart to purchase, enter 6\n"
				<< "To execute the puchase, enter 7\n"
				<< "To print all the buyers information, enter 8\n"
				<< "To print all the sellers information, enter 9\n"
				<< "To print all the products with the given name, enter 10\n"
				<< "To compere between two buyers with the operator >, enter 11\n"
				<< "To add buyer by operator +=, enter 12\n"
				<< "To add seller by operator +=, enter 13\n"
				<< "To add a user that is a buyer and a seller, enter 14\n"
				<< "To print all the MultiUsers, enter 15\n"
				<< "To show the use of the operator << on the classes 'Adrees', 'Date' and 'Feedback', enter 16\n"
				<< "To exit, enter 17\n"
				<< "------------------------------------------------------------\n";
			cin >> UserInput;
			UserChoice(UserInput, UserArr);
		} while (UserInput != 17);
		_CrtDumpMemoryLeaks();
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}