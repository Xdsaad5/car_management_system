#include <iostream>
#include <string>
#include "Login.h"
#include "Car.h"
#include "Admin.h"
#include "Seller.h"
#include "Store.h"
#include "Customer.h"
using namespace std;
int main()
{
	Admin ad;
	ad.menu();
	
	/*Seller s;
	s.addSeller();*/

	return 0;
}
/*ifstream fin("store.txt");
	if (!fin.is_open())
		cout << "Eror...!!!\n";
	string str;
	int temp;
	while (!fin.eof())
	{
		if (!fin.eof())
		{
			fin >> str;
			cout << str << '\n';
			fin >> str;
			cout << str << '\n';
			fin >> temp;
			cout << temp << '\n';
			fin >> temp;
			cout << temp << '\n';
		}
	}*/

//if (noOfCars == 0)
//{
//	cout << "In file if...\n";
//	ifstream fin("store.txt");
//	if (!fin.is_open())
//		cout << "Eror...!!!\n";
//	string strFile;
//	int temp;
//	while (!fin.eof())
//	{
//		if (!fin.eof())
//		{
//			fin >> strFile;
//			cout << strFile << '\n';
//			carList[noOfCars].setCarNumber(strFile);
//			fin >> strFile;
//			cout << strFile << '\n';
//			carList[noOfCars].setCarName(strFile);
//			fin >> temp;
//			cout << temp << '\n';
//			carList[noOfCars].setCarModel(temp);
//			fin >> temp;
//			cout << temp << '\n';
//			carList[noOfCars].setCarPrice(temp);
//			noOfCars++;
//			if (noOfCars == capacity)
//				reSize();
//		}
//	}
//}
//	}