#include <string>
using namespace std;
#ifndef PERSON_DATA_H
#define PERSON_DATA_H
class personData
{
	string name;
	string city;
	string address;
	int phNumb;
	
public:
	personData();
	personData(string, string, string, int);
	//getters
	string getName();
	string getCity();
	string getAddress();
	int getPhNumb();
	void setName(string);
	void setCity(string);
	void setAddress(string);
	void setphNumb(int);
};
#endif // !CAR_H
