#include <iostream>
#include <string>
#include "Login.h"
#include <fstream>
using namespace std;
void Login :: signUp(const string fileName)
{
	cout << "Enter Username. \n";
	getline(cin, userName);
	cout << "Enter Password (at least 8 characters).\n";
	getline(cin, password);
	ofstream fout(fileName);
	fout << userName << '\n' << password << '\n';
	fout.close();
}
bool Login::isAdmin()
{
	ifstream fin(fileName);
	if (!fin.is_open())
	{
		signUp(fileName);
		return true;
	}
	string name, pass;
	cout << "Enter your Username.\n";
	getline(cin, name);
	cout << "Enter Password (at least 8 characters).\n";
	getline(cin, pass);
	fin >> userName;
	fin >> password;
	if (name.compare(userName) == 0 && pass.compare(password) == 0)
	{
		cout << "Successfully Login.\n";
		return true;
	}
	else
	{
		cout << "Login_Falied.\n";
		exit(0);
	}
	return false;
}
void Login :: resetPassword()
{
	string name, pass;
	cout << "Enter your Username.\n";
	getline(cin, name);
	cout << "Enter your old Password.\n";
	getline(cin, pass);
	if (name.compare(userName) == 0 && pass.compare(password) == 0)
		signUp(fileName);
	else
		cout << "Password doesn't match.\nTry again.\n";
}