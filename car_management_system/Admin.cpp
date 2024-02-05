#include <iostream>
#include <string>
#include "Store.h"
#include "Login.h"
#include "Admin.h"
#include "Seller.h"
#include "Customer.h"
using namespace std;
Admin::Admin()
{
	/*if (!Login::isAdmin())
		return;*/
	fileName = "seller.txt";
}
string Admin::getFileName()
{
	return fileName;
}
void Admin::menu()
{
	char ch = 'y';
	cout << "-----Pres 1 To Enter Main Menu.-----\n";
	cout << "-----Pres 2 To Exit System.    -----\n";
	int option;
	cin >> option;
	if (option == 2)
		exit(0);
	Seller s;
	do
	{
		cout << "-----------------------------Welcome In Car Management System.------------------------------\n";
		cout << "1------------Admin--------------\n";
		cout << "2------------Seller-------------\n";
		cout << "3------------Customer-----------\n";
		cout << "Press 1 to Login as an Admin.\n";
		cout << "Press 2 to Login as an Seller.\n";
		cout << "Press 3 to Login as an Customer.\n";
		cin >> option;
		cin.ignore();
		if (option == 1)
		{
			bool status = this->isAdmin();
			if (status == false)
				continue;
			cout << "1----------Reset Password.----------\n";
			cout << "2----------List Of Seller.----------\n";
			cout << "3----------Store.         ----------\n";
			cin >> option;
			cin.ignore();
			if (option == 1)
				this->resetPassword();
			else if (option == 2)
				s.printListOfSeller();
			else if (option == 3)
			{
				cout << "1----------Display Store.----------\n";
				cout << "2----------Add a Car.----------\n";
				cout << "3----------Remove a Car.----------\n";
				int opt;
				cin >> opt;
				cin.ignore();
				if (opt == 1)
					this->printStore();
				else if (opt == 2)
					this->addCar();
				else if (opt == 3)
					this->removeCar();
			}
			option = 0;
		}
		else if (option == 2)
		{
			cout << "1----------Add a Seller.-------------\n";
			cout << "2----------Remove a Seller.----------\n";
			cout << "3----------Print List Of Seller.-----\n";
			cin >> option;
			cin.ignore();
			if (option == 1)
			{
				cout << "To Add Seller.\n Need Permission From Admin. \n" << "So,";
				if (s.isAdmin() == true)
					s.addSeller();
			}
			else if (option == 2)
			{
				cout << "To Remove Seller.\n Need Permission From Admin. \n" << "So,";
				if (s.isAdmin() == true)
					s.removeSeller();
			}
			else if (option == 3)
				s.printListOfSeller();
			option = 0;
		}
		else if (option == 3)
		{
			Customer c;
			cout << "1----------Add Customer.----------\n";
			cout << "2----------Add To Cart.-----------\n";
			cin >> option;
			cin.ignore();
			if (option == 1)
			{
				cout << "To Add Customer.\n Need Permission From Admin. \n" << "So,";
				if (isAdmin() == true)
					c.addCustomer();
			}
			else if (option == 2)
				c.addToCart();
			option = 0;
		}
		
		cout << "Do you Want to Continue.(y/Y)\n";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
