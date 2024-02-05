#include <string>
#include "Car.h"
using namespace std;
#ifndef STORE_H
#define STORE_H
class Store
{
	string fileName;
	int noOfCars;
	Car* carList;
	int capacity;
	void reSize();
	int searchCarNumb(string);
	void storeInFile();
public:
	Store();
	bool addCar();
	Car removeCar();
	int getNumberOfCars();
	void printStore();
	void takeDataFromFile();
	~Store();
};
#endif // !STORE_H
