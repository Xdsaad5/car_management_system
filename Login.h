#include <string>
using namespace std;
#ifndef LOGIN_H
#define LOGIN_H
class Login
{
	string userName;
	string password;
	string fileName;
	void signUp(const string);
public:
	Login() 
	{
		fileName = "pass.txt";
	};
	bool isAdmin();
	void resetPassword();
};
#endif // !LOGIN_H