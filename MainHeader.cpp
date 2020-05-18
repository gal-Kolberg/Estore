#include "MainHeader.h"
#include "UserManneger.h"
#include "Seller.h"
#include "Buyer.h"
#include "User.h"
#include "Date.h"
#include "Adress.h"
#include "Product.h"

void Case16Function(UserManneger &UserArr, int Userinput)
{ // Operator << for specific seller, prints it's feedback and dates
	string user_name = ReciveUserName(Userinput); // getting input from user
	string user_password = ReciveUserPassword(); // getting input from user
	int index = UserArr.Login(user_name, user_password); // login
	if (index != USER_NOT_FOUND)
		if (UserArr.getUserArr()[index]->IsSeller() == true) // only seller have date and feedback to show
		{
			Seller *s1 = UserArr.getUserArr()[index]->getSeller();
			int size_of_feedbacks = s1->getFeedback().getLogicalSize();
			if(size_of_feedbacks != 0)
				cout << "All the feedback of this seller are:\n";
			for (int i = 0; i < size_of_feedbacks; i++)
				cout << s1->getFeedback()[i]; // this operator uses the oprator << of date aswell 
			Adress *a1 = UserArr.getUserArr()[index]->getAdress();
			cout << "The seller lives at:\n" << *a1; // showing with adress with the operator <<
		}
		else
			cout << "A buyer doesn't have feedback to show\n\n";
}

void Case14Function(UserManneger &UserArr, int Userinput)
{ // To add a user that is a seller and a buyer
	string user_name = ReciveUserName(Userinput); // gets the user name that will be added
	if (UserArr.ValidateNameBool(user_name) == true)  // validates it, if the name is take or not
	{
		cout << "You have chosen a user name that is already taken, try again\n\n";
		return;
	}
	string user_password = ReciveUserPassword(); // gets the password
	UserArr.AddUser(Userinput, user_name, user_password, ReciveAdress(),false); // add the user with the given user name and password
}

void Case13Function(UserManneger &UserArr)
{ // Add seller by operator +=
	string user_name = ReciveUserName(2); // gets the user name that will be added, 2 : means seller
	if (UserArr.ValidateNameBool(user_name) == true)  // validates it, if the name is take or not
	{
		cout << "You have chosen a user name that is already taken, try again\n\n";
		return;
	}
	string user_password = ReciveUserPassword(); // gets the password
	Seller seller;
	seller.setName(user_name);
	seller.setPassword(user_password);
	seller.setAdress(ReciveAdress());
	UserArr += seller;
}

void Case12Function(UserManneger &UserArr)
{ // Add buyer by operator +=
	string user_name = ReciveUserName(1); // gets the user name that will be added, 1 : means buyer
	if (UserArr.ValidateNameBool(user_name) == true)  // validates it, if the name is take or not
	{
		cout << "You have chosen a user name that is already taken, try again\n\n";
		return;
	}
	string user_password = ReciveUserPassword(); // gets the password
	Buyer buyer;
	buyer.setName(user_name);
	buyer.setPassword(user_password);
	buyer.setAdress(ReciveAdress());
	UserArr += buyer;
}

void Case11Function(UserManneger &UserArr)
{ // To compere between two buyers with the operator >
	cout << "Please choose 2 buyer name: (enter by name)\n";
	UserArr.PrintAllBuyersByName();
	string name_b1;
	string name_b2;
	cin >> name_b1 >> name_b2;
	Buyer* b1 = UserArr.getBuyerByName(name_b1);
	Buyer* b2 = UserArr.getBuyerByName(name_b2);
	if (b1 == nullptr || b2 == nullptr)
	{
		cout << "One or more of the buyer name was invalid, please try agian\n";
		return;
	}
	if (*b1 > *b2)
		cout << name_b1;
	else if (*b2 > *b1)
		cout << name_b2;
	else
		cout << "nobody";
	cout << "'s interested cart is more expensive\n\n";
}

void Case7Function(UserManneger &UserArr, int Userinput)
{
	string user_name = ReciveUserName(Userinput); // getting input from user
	string user_password = ReciveUserPassword(); // getting input from user
	int index = UserArr.Login(user_name, user_password); // login
	if (index != USER_NOT_FOUND)
		if (UserArr.getUserArr()[index]->IsBuyer() == true) // only buyer can make a purchase
		{
			Buyer *buyer =UserArr.getUserArr()[index]->getBuyer(); // get the buyer
			if (buyer->getCart()->getSelected().size() == 0) // checks if there are items in the selected items
			{
				cout << "It seems like you haven't choose anything yet, why not start now?\n\n";
				return;
			}
			buyer->AddPurchase(); // adds the purchase to the ordered
			cout << "The purchase is now complete!\n\n";
		}
		else
			cout << "A seller can not make a purchase\n\n";
}

void Case6Function(UserManneger &UserArr, int Userinput)
{
	string user_name = ReciveUserName(Userinput); // getting input from user
	string user_password = ReciveUserPassword(); // getting input from user
	int index = UserArr.Login(user_name, user_password); // login
	if (index != USER_NOT_FOUND)
		if (UserArr.getUserArr()[index]->IsBuyer() == true) // only buyer can add a product to cart
		{
			Buyer *buyer = UserArr.getUserArr()[index]->getBuyer();  // get the buyer
			if (buyer->getCart()->getInterested().size() == 0) // checks if there are items in the 'Interested' cart
			{
				cout << "No Items have been found in your 'Interested' cart, why not start now?\n\n";
				return;
			}
			buyer->getCart()->PrintAllInterested();	 // print all the products in the 'Interested' cart
			int howMany = ReciveHowManyProducts((int)buyer->getCart()->getInterested().size()); // get how many products the user want to buy
			int *IndexArr = ReciveIndexProducts(howMany,(int)buyer->getCart()->getInterested().size()); // getting input from user
			if (IndexArr == nullptr)
				return;
			buyer->getCart()->MoveToSelected(IndexArr, howMany); // get all the products ready for purchase
			delete[] IndexArr;
		}
		else
			cout << "A seller can not do this kind of action\n\n";
}

void Case5Function(UserManneger &UserArr, int Userinput)
{
	string user_name = ReciveUserName(Userinput); // getting input from user
	string user_password = ReciveUserPassword(); // getting input from user
	int index = UserArr.Login(user_name, user_password); // login
	if (index != USER_NOT_FOUND)
		if (UserArr.getUserArr()[index]->IsBuyer() == true) // only buyer can add a product to cart
		{
			int Categoeychoice, Choice, NumOfReleventProducts;
			Buyer *b1 = UserArr.getUserArr()[index]->getBuyer(); // get the buyer
			Categoeychoice = ReciveCategoryChoice();			 // get what kind of category the user wants to buy 
			if (UserArr.categoryExists(Categoeychoice) == false) // checks if there are items in the wanted category
			{
				cout << "No Item found in this category\n\n";
				return;
			}
			NumOfReleventProducts = b1->PrintAllCategeryProducts(UserArr, Categoeychoice); // prints all products by category
			Choice = ReciveChoice(NumOfReleventProducts); // gets the choice of the use 
			Product *p1 = b1->AddProductToCart(UserArr, Categoeychoice, Choice);
			UserArr.AddProdctToIntereseted(index, p1);// adds to interested product that has been selected
		}
		else
			cout << "A seller can not add a product to cart\n\n";
}

void Case4Function(UserManneger &UserArr, int Userinput)
{
	string user_name = ReciveUserName(Userinput); // getting input from user
	string user_password = ReciveUserPassword(); // getting input from user
	int index = UserArr.Login(user_name, user_password); // login
	if (index != USER_NOT_FOUND)
		if (UserArr.getUserArr()[index]->IsBuyer() == true) // only buyer can add a feedback
		{
			Buyer *b1 = UserArr.getUserArr()[index]->getBuyer(); // get the buyer
			int count = 0;
			if (b1->ChooseProduct(UserArr, index, count)) //print all the products the buyer has bought 
			{
				string s_name = b1->FindProduct(ReciveProductNumber(count)); // get the number of item the buyer wants to give feedback about
				if (s_name == "") // the pointer will be nullptr if it does not exists
				{
					cout << "Product Not Found!\n\n";
					return;
				}
				Seller *s1 = UserArr.FindSeller(s_name); // get the seller
				Date* temp_date = ReciveDate();
				string temp_feedback = ReciveFeedback();
				Feedback *f1 = b1->Givefeedback(temp_feedback, temp_date); // get the string feedback and the date from a function in the mainheader and set them to the seller
				s1->AddFeedback(*f1);
				cout << "Feedback added succssefully\n\n";
				delete f1;
			}
		}
		else
			cout << "A seller can not add a feedback\n\n";
}

void Case3Function(UserManneger &UserArr, int Userinput)
{
	string user_name = ReciveUserName(Userinput); // getting input from user
	string user_password = ReciveUserPassword(); // getting input from user
	int index = UserArr.Login(user_name, user_password); // login
	if (index != USER_NOT_FOUND)
	{
		if (UserArr.getUserArr()[index]->IsSeller() == true) // only seller can add new product to his shop
		{
			string product_name = ReciveProductName(); // getting input from user
			double product_price = ReciveProductPrice(); // getting input from user
			int product_category = ReciveCategoryChoice(); // getting input from user
			// get all the product info and then add the product to the seller
			UserArr.AddProductToSeller(index, product_name, product_price, product_category);
		}
		else
			cout << "A buyer can not add a product for sale\n\n";
	}
}

void CaseAddSellerBuyerFunction( UserManneger &UserArr, int Userinput)
{
	string user_name = ReciveUserName(Userinput); // gets the user name that will be added
	if (UserArr.ValidateNameBool(user_name) == true)  // validates it, if the name is take or not
	{
		cout << "You have chosen a user name that is already taken, try again\n\n";
		return;
	}
	string user_password = ReciveUserPassword(); // gets the password
	UserArr.AddUser(Userinput, user_name, user_password,ReciveAdress(),false); // add the buyer with the given user name and password
}

int IntegerChecker(int val, int min, int max, const string message) // checks an integer from a given range
{
	int i;
	for (i = 0; (val < min || val > max) && i < 3; i++)
	{
		cout << "The "<< message << " is invalid try again\n";
		cout << "You have tries 3 in total, " << 3 - i << " to go\n";
		cin >> val;
	}
	if (i == 3 && (val < min || val > max))
	{
		cout << "Wrong " << message << " bye bye\n\n";
		exit(1);
	}
	return val;
}

double FloatChecker(double val, double min, double max, const string message) // checks an integer from a given range
{
	int i;
	for (i = 0; (val < min || val > max) && i < 3; i++)
	{
		cout << "The " << message << " is invalid try again\n";
		cout << "You have tries 3 in total, " << 3 - i << " to go\n";
		cin >> val;
	}
	if (i == 3 && (val < min || val > max))
	{
		cout << "Wrong " << message << " bye bye\n\n";
		exit(1);
	}
	return val;
}

int ReciveCategoryChoice() // returns an int choice
{
	int Categoeychoice;
	cout << "Please enter the product type you wish to buy:";
	cout << "\n 0 for kids \n 1 for Electronics \n 2 for Office \n 3 for Clothing \n";
	cin >> Categoeychoice;
	return IntegerChecker(Categoeychoice, 0, 3, "category");
}

int ReciveChoice(int NumOfReleventProducts) // returns the number of products selected
{
	int Choice;
	cout << "Enter the index number of the product you wish to buy\n";
	cin >> Choice;
	return IntegerChecker(Choice, 1, NumOfReleventProducts, "number");
}

double ReciveProductPrice() // return the recived price
{
	double itemPrice;
	cout << "Please enter the product price:\n";
	cin >> itemPrice;
	return FloatChecker(itemPrice, 0, 99999999, "price");
}

string ReciveProductName() // return the product name
{
	string itemName;
	cout << "Please enter product name(max 255 chars):\n";
	getline(cin, itemName);
	return itemName;
}

string ReciveUserPassword()
{
	string password;
	cout << "Please enter password:\n";
	getline(cin, password);
	return password;
}

string ReciveUserName(int input) // General function to input a user name from the user, whether the user logs in or make a new user 
{
	string name;
	if (input == 1 || input == 2 || input == 14)
		cout << "Please enter your wanted username:\n";
	else
		cout << "For validation reasons\nPlease enter username:\n";
	cin.ignore();
	getline(cin, name);
	return name;
}

Date *ReciveDate()
{
	int day, month, year;
	cout << "Please enter the Date in this format: dd mm yyyy\n";
	cin >> day >> month >> year;
	day = IntegerChecker(day, 1, 31, "day input");
	month = IntegerChecker(month, 1, 12, "month input");
	year = IntegerChecker(year, 0, 3000, "year input");
	Date* d1 = new Date(day, month, year);
	return d1;
}

string ReciveFeedback()
{
	string feedback;
	cout << "Please Enter the feedback for the product(max 255 chars):\n";
	cin.ignore();
	getline(cin, feedback);
	return feedback;
}

string ReciveCity()
{
	string city;
	cout << "Please enter city (max 255 char):\n";
	getline(cin, city);
	return city;
}

string ReciveStreet()
{
	string street;
	cout << "Please enter Street (max 255 char):\n";
	getline(cin, street);
	return street;
}

int ReciveHousenumber()
{
	int HouseNumber;
	cout << "Please enter house number:\n";
	cin >> HouseNumber;
	return IntegerChecker(HouseNumber,0,10000000,"house number");
}

Adress* ReciveAdress()
{
	Adress* temp = new Adress;
	temp->setCity(ReciveCity());
	temp->setStreet(ReciveStreet());
	temp->setHouseNumber(ReciveHousenumber());
	return temp;
}

int ReciveHowManyProducts(int max)
{
	int num;
	cout << "How many products do you wish to purchase:\n";
	cin >> num;
	return IntegerChecker(num, 1, max, "number of products");
}

int* ReciveIndexProducts(int size, int MaxChoise)
{
	int *indexArr = new int[size];
	int input;
	cout << "Please enter which product do you want to buy(select their index)\n";
	for (int i = 0; i < size; i++)
	{
		cin >> input;
		if (input < 1 || input > MaxChoise)
		{ // checks if the input index is valid
			cout << "You chose a index that was invalid\n\n";
			delete[] indexArr;
			return nullptr;
		}
		for (int j = 0; j < i; j++)
		{
			if (input == indexArr[j]) // checks if a given value has been given before
			{
				cout << "You have entered the same number twice, you can add an item only once, try again\n\n";
				delete[] indexArr;
				return nullptr;
			}
		}
		indexArr[i] = input;
	}
	return indexArr;
}

int ReciveProductNumber(int max)
{
	int num;
	cin >> num;
	return IntegerChecker(num, 0, max, "Product number (not in range)\n") - 1;
}