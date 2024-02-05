#include <iostream>
#include <string>
#include "Car.h"
using namespace std;
Car::Car()
{
	carModel = 0;
	price = 200000;
	carName = " ";
	carNumber = " ";
}
Car::Car(string name,  string numb , int mod, int cost)
{
	carName = name;
	carModel = mod;
	carNumber = numb;
	setCarPrice(cost);
}
//getters:
string  Car::getCarNumber()
{
	return carNumber;
}
string Car :: getCarName()
{
	return carName;
}
int Car::getCarModel()
{
	return carModel;
}
int Car::getCarPrice()
{
	return price;
}
//setters
void Car::setCarNumber(string numb)
{
	carNumber = numb;
}
void Car :: setCarName(string name)
{
	carName = name;
}
void Car :: setCarModel(int mod)
{
	carModel = mod;
}
void  Car ::setCarPrice(int cost)
{
	if (cost < 200000)
		price = 200000;
	price = cost;
}