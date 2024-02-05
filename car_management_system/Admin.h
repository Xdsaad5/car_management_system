#include "Login.h"
#include "Car.h"
#include "Store.h"
using namespace std;
#ifndef ADMIN_H
#define ADMIN_H
class Admin : public Login , public Store
{
	string fileName;
public:
	Admin();
	string getFileName();
	virtual void addSeller() {}
	virtual void removeSeller() {}
	virtual void printListOfSeller() {}
	/*virtual bool addCar();
	virtual Car removeCar();
	virtual int getNumberOfCars();
	virtual void printStore();*/
	void menu();
};
#endif // !ADMIN_H
