#include <iostream>
#include <fstream>
#include <string>
#include "Customer.h"
#include "Store.h"
using namespace std;
Customer::Customer()
{
	fileName = "customer.txt";
	noOfCustomer = 0;
	personList = nullptr;
	capacity = 0;
}
int Customer::getNumberOfCustomer()
{
	return noOfCustomer;
}
void Customer::addCustomer()
{
	ofstream fout(fileName);
	if (!fout.is_open())
	{
		cout << "Eror...in file.\n";
			return;
	}
	string str;
	cout << "Enter Customer Name.\n";
	getline(cin, str);
	fout << str << '\n';
	cout << "Enter Customer's city.\n";
	getline(cin, str);
	fout << str << '\n';
	cout << "Enter Customer Address.\n";
	getline(cin, str);
	fout << str << '\n';
	int phno;
	cout << "Enter Customer phone Number.\n";
	cin >> phno;
	cin.ignore();
	fout << phno << '\n';
	noOfCustomer++;

}
void Customer:: addToCart()
{
	Store s;
	s.printStore();
	Car obj = s.removeCar();
	if (obj.getCarName() == " ")
		return;
}