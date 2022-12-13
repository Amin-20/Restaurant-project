#include<iostream>
#include<assert.h>
#include<string>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<windows.h>
#include<vector>
#include"Entities.h"
#include"Admin.h"
#include"Guest.h"
using namespace std;

void mysetcolor(int fg, int bg)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(h, fg | (bg << 4));
}

void main() {
	Product p("Tomato", 0.4, 18, 100);
	Product p1("Olive", 0.1, 115, 100);
	Product p2("Mashroom", 0.8, 22, 100);
	Product p3("Flour", 1, 364, 100);
	Product p4("Cucumber", 1, 364, 100);

	Stock stocksave;
	stocksave.AddProduct(p);
	stocksave.AddProduct(p1);
	stocksave.AddProduct(p2);
	stocksave.AddProduct(p3);
	stocksave.AddProduct(p4);
	Meal f(20, "Mozerella");
	f.AddProduct(p);
	f.AddProduct(p1);
	f.AddProduct(p2);
	f.AddProduct(p3);
	Meal f1(13, "Sezar");
	f1.AddProduct(p);
	f1.AddProduct(p1);
	Kitchen k;
	k.AddMeal(f);
	k.AddMeal(f1);
	Client c1;
	c1.AddMenu(k);
	//FileHelper::Save(stocksave);
	Stock stock = FileHelper::Read();

	Meal m;
	Table t;
	Notification n;

#pragma region START
	double totalPrice = 0;
	while (true)
	{
		system("cls");

		mysetcolor(4, 0);																					                                                                                             
		cout << "                                                                                               (                                                                                                     " << endl;
		cout << "                                                                              *   )   )        )\\ ) (                      (  (           )                                                         " << endl;
		cout << "                                                                            ` )  /(( /(   (   (()/( )\\(   (        (  (    )\\))(   '   ( /(                                                        " << endl;
		cout << "                                                                             ( )(_))\\()) ))\\   /(_)|(_)\\ ))\\  (    )\\))(  ((_)()\\ ) (  )\\())                                                  " << endl;
		cout << "                                                                            (_(_()|(_)\\ /((_) (_))_|_(()/((_) )\\ )((_))\\  _(())\\_)())\\((_)\\                                                    " << endl;
		mysetcolor(11, 0);
		cout << "                                                                            |_   _| |(_|_))   | |_ | |)(_)|_)_(_/( (()(_) \\ \\((_)/ ((_) |(_)                                                       " << endl;
		cout << "                                                                              | | | ' \\/ -_)  | __|| | || | | ' \\)) _` |   \\ \\/\\/ / _ \\ / /                                                    " << endl;
		cout << "                                                                              |_| |_||_\\___|  |_|  |_|\\_, |_|_||_|\\__, |    \\_/\\_/\\___/_\\_\\                                                  " << endl;
		cout << "                                                                                                      |__/        |___/                                                                              " << endl;		
		cout << "                                                                                                                                                                                                     " << endl;
		mysetcolor(3, 0);
		cout << "                                                                                                  _                              _                                     	                         " << endl;
		cout << "                                                                                    _ __ ___  ___| |_ __ _ _   _ _ __ __ _ _ __ | |_ 	                                                             " << endl;
		cout << "                                                                                   | '__/ _ \\/ __| __/ _` | | | | '__/ _` | '_ \\| __|	                                                         " << endl;
		cout << "                                                                                   | | |  __/\\__ \\ || (_| | |_| | | | (_| | | | | |_ 	                                                         " << endl;
		cout << "                                                                                   |_|  \\___||___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__|	                                                     " << endl;
		cout << "                                                                                                                                         	                                                         " << endl;
		cout << "			                           											                                                                                                                     " << endl;
		mysetcolor(7, 0);
		cout << "                                                                                                        CLIENT [1]                                                                                  " << endl << endl;
		cout << "                                                                                                        ADMIN  [2]                                                                                  " << endl << endl;
		cout << "                                                                                                    Enter select [1/2] : ";
		string select;
		cin >> select;
		cout << endl << endl;
		if (select == "1") {
			mysetcolor(14, 0);
			cout << "                                                                                                   1) Table T-20" << endl << endl;
			cout << "                                                                                                   2) Table E-2" << endl << endl;
			cout << "                                                                                                   3) Table Y-4" << endl << endl;
			cout << "                                                                                                   4) Table EI-12" << endl << endl;
			cout << "                                                                                                   5) Table ViP-1 " << endl << endl;
			cout << "                                                                                                   Enter tableNo : ";
			
			int tableNo;
			cin >> tableNo;
			Client c(tableNo);
			c.AddMenu(k);
			ClientMenu(totalPrice, c, k, stock, n, t);
		}
		else if (select == "2") {
			system("cls");
			while (true)
			{
				cin.ignore();
				cin.clear();
				system("cls");
				cout << endl;
				cout << "                                                  Enter username : ";
				string username;
				getline(cin, username);
				system("cls");
				cout << "                                                  Enter Password: ";
				string password, P;
				char p;
				p = _getch();
				while (p != 13)
				{
					if (p == 8)
					{
						P.resize(P.length() - 1);
						cout << P;
						password.resize(password.length() - 1);
					}
					else {
						P = P + "*";
						cout << P;
						password.push_back(p);
					}
					p = _getch();
					if (p != 13) {
						system("cls");
						cout << "                                                  Enter Password: ";
					}
				}
				cout << endl;
				if (username == "admin") {
					if (password == "admin") {
						AdminMenu(k, stock, c1, t);
						break;
					}
					else {
						mysetcolor(4, 0);
						cout << "                                                  Wrong password!" << endl;
						mysetcolor(7, 0);
					}
				}
				else {
					mysetcolor(4, 0);
					cout << "                                                  Wrong username!" << endl;
					mysetcolor(7, 0);
				}
			}
		}
		else {
			cout << "                                                  Your select is incorrect!!!\n";
			cout << "                                                  Please enter retry" << endl;
		}
		system("pause");
	}
#pragma endregion	
}



