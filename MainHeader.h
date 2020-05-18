#ifndef __MAINHEADER_H
#define __MAINHEADER_H

#define SIZE 100
#define MALLOC_ERROR_CODE -1

#include <string>
#include <vector>

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

#pragma warning(disable: 4996)

//const int MAX_LEGHTH = 255;
const int USER_NOT_FOUND = -1;
//const int MAX_HOUSE_NUMBER = 100000000;

template<class T>
class Array;
class UserManneger;
class Seller;
class Buyer;
class Adress;
class Date;

int IntegerChecker(int val, int min, int max, const string message);

void CaseAddSellerBuyerFunction(UserManneger &UserArr, int Userinput);
void Case3Function(UserManneger &UserArr, int Userinput);
void Case4Function(UserManneger &UserArr, int Userinput);
void Case5Function(UserManneger &UserArr, int Userinput);
void Case6Function(UserManneger &UserArr, int Userinput);
void Case7Function(UserManneger &UserArr, int Userinput);
void Case11Function(UserManneger &UserArr);
void Case12Function(UserManneger &UserArr);
void Case13Function(UserManneger &UserArr);
void Case14Function(UserManneger &UserArr, int Userinput);
void Case16Function(UserManneger &UserArr, int Userinput);

int ReciveCategoryChoice();
int ReciveChoice(int NumOfReleventProducts);
double ReciveProductPrice();
string ReciveProductName();
string ReciveUserPassword();
string ReciveUserName(int input);
Date *ReciveDate();
string ReciveFeedback();
string ReciveCity();
string ReciveStreet();
int ReciveHousenumber();
Adress* ReciveAdress();
int ReciveHowManyProducts(int max);
int* ReciveIndexProducts(int size, int MaxChoise);
int ReciveProductNumber(int max);

#endif // !__MAINHEADER_H
