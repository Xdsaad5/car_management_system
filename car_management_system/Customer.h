#include "Admin.h"
#include "Store.h"
#include "personData.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
	string fileName;
	int noOfCustomer;
	personData* personList;
	int capacity;
	void reSize();
	int searchCustomer(string);
	void storeInFile();
public:
	Customer();
	void addCustomer();
	int getNumberOfCustomer();
	void addToCart();


};
#endif // !CUSTOMER_H
