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
	Meal f(20, "Moz");
	f.AddProduct(p);
	f.AddProduct(p1);
	f.AddProduct(p2);
	f.AddProduct(p3);
	Meal f1(13, "SeMzar");
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

		mysetcolor(11, 0);
		cout << "                                                          _____                    _____                    _____                    _____                _____          	                         " << endl;
		cout << "                                                         /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\              /\\    \\         	             " << endl;
		cout << "                                                        /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\            /::\\    \\        	             " << endl;
		cout << "                                                       /::::\\    \\              /::::\\    \\              /::::\\    \\              /::::\\    \\           \\:::\\    \\       	             " << endl;
		cout << "                                                      /::::::\\    \\            /::::::\\    \\            /::::::\\    \\            /::::::\\    \\           \\:::\\    \\      	             " << endl;
		cout << "                                                     /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\           \\:::\\    \\     	         " << endl;
		cout << "                                                    /:::/  \\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\           \\:::\\    \\    	         " << endl;
		cout << "                                                   /:::/    \\:::\\    \\      /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\          /::::\\    \\   	         " << endl;
		cout << "                                                  /:::/    / \\:::\\    \\    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\        /::::::\\    \\  	         " << endl;
		cout << "                                                 /:::/    /   \\:::\\ ___\\  /:::/\\:::\\   \\:::\\____\\  /:::/\\:::\\   \\:::\\    \\  /:::/\\:::\\   \\:::\\    \\      /:::/\\:::\\    \\       " << endl;
		cout << "                                                /:::/____/  ___\\:::|    |/:::/  \\:::\\   \\:::|    |/:::/__\\:::\\   \\:::\\____\\/:::/  \\:::\\   \\:::\\____\\    /:::/  \\:::\\____\\	         " << endl;
		cout << "                                                \\:::\\    \\ /\\  /:::|____|\\::/   |::::\\  /:::|____|\\:::\\   \\:::\\   \\::/    /\\::/    \\:::\\  /:::/    /   /:::/    \\::/    /	         " << endl;
		cout << "                                                 \\:::\\    /::\\ \\::/    /  \\/____|:::::\\/:::/    /  \\:::\\   \\:::\\   \\/____/  \\/____/ \\:::\\/:::/    /   /:::/    / \\/____/ 	         " << endl;
		cout << "                                                  \\:::\\   \\:::\\ \\/____/         |:::::::::/    /    \\:::\\   \\:::\\    \\               \\::::::/    /   /:::/    /          	             " << endl;
		cout << "                                                   \\:::\\   \\:::\\____\\           |::|\\::::/    /      \\:::\\   \\:::\\____\\               \\::::/    /   /:::/    /           	             " << endl;
		cout << "                                                    \\:::\\  /:::/    /           |::| \\::/____/        \\:::\\   \\::/    /               /:::/    /    \\::/    /                                " << endl;
		cout << "                                                     \\:::\\/:::/    /            |::|  ~|               \\:::\\   \\/____/               /:::/    /      \\/____/                                  " << endl;
		cout << "                                                      \\::::::/    /             |::|   |                \\:::\\    \\                  /:::/    /                           	                     " << endl;
		cout << "                                                       \\::::/    /              \\::|   |                 \\:::\\____\\                /:::/    /                            	                     " << endl;
		cout << "                                                        \\::/____/                \\:|   |                  \\::/    /                \\::/    /                             	                     " << endl;
		cout << "                                                                                  \\|___|                   \\/____/                  \\/____/                              	                     " << endl;
		cout << "                                                                                                                                                                            	                     " << endl;
		cout << "                                                                                                                                                                                                    " << endl;
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
		if (select == "1") {
			system("cls");
			cout << "1) Table T-20" << endl;
			cout << "2) Table E-2" << endl;
			cout << "3) Table Y-4" << endl;
			cout << "4) Table EI-12" << endl;
			cout << "5) Table ViP-1 " << endl;
			cout << "Enter tableNo : ";
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
				cout << "Enter username : ";
				string username;
				getline(cin, username);
				system("cls");
				cout << "Enter Password: ";
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
						cout << "Enter Password: ";
					}
				}
				cout << endl;
				if (username == "admin") {
					if (password == "admin") {
						AdminMenu(k, stock, c1, t);
						break;
					}
					else {
						cout << "Wrong password!" << endl;
					}
				}
				else {
					cout << "Wrong username!" << endl;
				}
			}
		}
		else {
			cout << "Your select is incorrect!!!\n";
			cout << "Please enter retry" << endl;
		}
		system("pause");
	}
#pragma endregion	
}












