#include <string>
using namespace std;
#ifndef CAR_H
#define CAR_H
class Car
{
	string carName;
	string carNumber;
	int carModel;
	int price;
public:
	Car();
	Car(string, string , int , int);
	//getters
	string getCarNumber();
	string getCarName();
	int getCarModel();
	int getCarPrice();
	void setCarNumber(string);
	void setCarName(string);
	void setCarModel(int);
	void setCarPrice(int);
};
#endif // !CAR_H
