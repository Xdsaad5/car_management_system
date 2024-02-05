#include <iostream>
#include <fstream>
#include <string>
#include "Store.h"
#include "Login.h"
using namespace std;
Store::Store()
{
	fileName = "store.txt";
	noOfCars = 0;
	carList = nullptr;
	capacity = 0;
	takeDataFromFile();
	//cout << "remove = " << std::remove("store.txt");
}
int Store::getNumberOfCars()
{
	return noOfCars;
}
void Store:: reSize()
{
	/*if (capacity == 0)
		capacity = 1;
	else*/
		capacity = capacity + 10;
	Car* ptr = new Car[capacity];
	for (int i = 0; i < noOfCars; i++)
	{
		ptr[i].setCarName(carList[i].getCarName());
		ptr[i].setCarNumber(carList[i].getCarNumber());
		ptr[i].setCarModel(carList[i].getCarModel());
		ptr[i].setCarPrice(carList[i].getCarPrice());
	}
	this->~Store();
	carList = ptr;
}
int Store::searchCarNumb(string key)
{
	for (int i = 0; i < noOfCars; i++)
	{
		if (key.compare(carList[i].getCarNumber()) == 0)
			return i;
	}
	return -1;
}
bool Store::addCar()
{
	string str;
	cout << "Enter Number of Car.\n";
	getline(cin, str);
	if (searchCarNumb(str) != -1)
	{
		cout << "Car has already been added.\n";
		return false;
	}
	if (noOfCars == capacity)
		reSize();
	string str2;
	cout << "Enter Name of Car.\n";
	getline(cin, str2);
	carList[noOfCars].setCarName(str2);
	carList[noOfCars].setCarNumber(str);
	cout << "Enter Model of Car.\n";
	int temp;
	cin >> temp;
	carList[noOfCars].setCarModel(temp);
	cout << "Enter Price of Car.\n";
	cin >> temp;
	cin.ignore();
	carList[noOfCars].setCarPrice(temp);
	noOfCars++;
	cout << "Successfully Added.\n";
	storeInFile();
	return true;
}
void Store :: storeInFile()
{
	ofstream fout("store.txt");
	if (!fout.is_open())
		cout << "Eror...\n";
	for (int i = 0; i < noOfCars; i++)
	{
		fout << carList[i].getCarNumber() << '\n';
		fout << carList[i].getCarName() << '\n';
		fout << carList[i].getCarModel() << '\n';
		fout << carList[i].getCarPrice() << '\n';
	}
	fout.close();
}
Store:: ~Store()
{
	if (carList == nullptr)
		return;
	delete[] carList;
	carList = nullptr;
}
void Store ::printStore()
{
	for (int i = 0; i < noOfCars; i++)
	{
		cout<<"Name = " << carList[i].getCarName() << '\n';
		cout<<"number = "<<carList[i].getCarNumber() << '\n';
		cout<<"model = "<<carList[i].getCarModel() << '\n';
		cout<<"price = "<<carList[i].getCarPrice() << '\n'<<'\n';
	}

}
Car Store::removeCar()
{
	if (noOfCars == 0)
	{
		cout << "Store is empty.\n";
		cout << "Un_able to Delete Record.\n";
	}
	cout << "Enter Number of car.\n";
	string str;
	getline(cin, str);
	Car obj;
	if (searchCarNumb(str) == -1)
	{
		cout << "Car Not Found.\n";
		return obj;
	}
	int status = searchCarNumb(str);
	obj.setCarName(carList[status].getCarName());
	obj.setCarNumber(carList[status].getCarNumber());
	obj.setCarModel(carList[status].getCarModel());
	obj.setCarPrice(carList[status].getCarPrice());

	carList[status].setCarName(carList[noOfCars-1].getCarName());
	carList[status].setCarNumber(carList[noOfCars-1].getCarNumber());

	carList[status].setCarModel(carList[noOfCars-1].getCarModel());
	carList[status].setCarPrice(carList[noOfCars-1].getCarPrice());
	noOfCars--;
	cout << "Successfully Deleted.\n";
	storeInFile();
	return obj;
}
void Store :: takeDataFromFile()
{
	ifstream fin("store.txt");
	string str;
	int temp;
	reSize();
	while (!fin.eof())
	{
		if (!fin.eof())
		{
			fin >> str;
			carList[noOfCars].setCarNumber(str);
			fin >> str;
			carList[noOfCars].setCarName(str);
			fin >> temp;
			carList[noOfCars].setCarModel (temp);
			fin >> temp;
			carList[noOfCars].setCarPrice(temp);
			noOfCars++;
		}
	}
	noOfCars--;
 }