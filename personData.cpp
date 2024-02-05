#include <iostream>
#include <string>
#include "personData.h"
using namespace std;
personData::personData()
{
	name = " ";
	city = " ";
	address = " ";
	phNumb = 0;
}
personData::personData(string n, string cit, string add, int mobNumb)
{
	name = n;
	city = cit;
	address = add;
	phNumb = mobNumb;
}
//getters:
string  personData::getName()
{
	return name;
}
string personData::getCity()
{
	return city;
}
string personData::getAddress()
{
	return address;
}
int personData::getPhNumb()
{
	return phNumb;
}
//setters
void personData::setName(string n)
{
	name = n;
}
void personData::setCity(string cit)
{
	city = cit;
}
void personData::setAddress(string add)
{
	address = add;
}
void personData::setphNumb(int mobNumb)
{
	phNumb = mobNumb;
}