#include <iostream>
#include "Admin.h"
#include <string>
#include <fstream>
using namespace std;
#ifndef SELLER_H
#define SELLER_H
class Seller:public Admin
{
	string name;
	float CNIC;
	string fName;
public:
	Seller()
	{
		name = "";
		CNIC = 00000000;
		fName = Admin::getFileName();
	}
	void addSeller()
	{
		ofstream fout(Admin::getFileName(), ios::app);
		if (!fout.is_open())
			cout << "Eror in file.\n";
		cout << "Enter name of Seller.\n";
		getline(cin, name);
		cout << "Enter  CNIC of  Seller.\n";
		cin >> CNIC;
		cin.ignore();
		int status = alreadyMember(CNIC);
		if (status != -1)
		{
			cout << "Already Added.\n";
			return;
		}
		int i = 0;
		fout << CNIC << '\n';
		while (name[i] != '\0')
		{
			fout << name[i];
			i++;
		}
		fout << '\n';
	}
private:	
	int alreadyMember(float id)
	{
		ifstream  fin(Admin::getFileName());
		if (!fin.is_open())
			cout << "Eror in file.\n";
		float temp[100];
		string str[100];
		int i = 0 , rmv;
		while (!fin.eof())
		{
			fin >> temp[i];
			fin >> str[i];
			if (id == temp[i] && !fin.eof())
				return i;
			i++;
		}
		//cout << Admin::getFileName() << '\n';
		//cout << std::remove("seller.txt") << '\n';
		fin.close();
		return -1;
	}
public:
	void removeSeller()
	{
		float id;
		cout << "Enter CNIC of  Seller.\n";
		cin >> id;
		ifstream  fin(Admin::getFileName());
		if (!fin.is_open())
			cout << "Eror in file.\n";
		float temp[1000];
		string str[1000];
		int i = 0, rmv;
		while (!fin.eof())
		{
			fin >> temp[i];
			fin >> str[i];
			if (id == temp[i] && !fin.eof())
				rmv = i;
			i++;
		}
		
		cout << std::remove("seller.txt") << '\n';
		fin.close();
		ofstream fout(Admin::getFileName());
		if (!fout.is_open())
			cout << "Eror in file.\n";
		int j = 0;
		while (j < i)
		{
			if (rmv != j)
			{
				fout << temp[j] << '\n';
				fout << str[j] << '\n';
			}
			j++;
		}
		fout.close();
	}
	void printListOfSeller()
	{
		ifstream fin(Admin::getFileName());
		float id;
		string name;
		cout << "Name.\t" << "\tCNIC.\t" << '\n';
		while (!fin.eof())
		{
			fin >> id;
			fin >> name;
			if (!fin.eof())
				cout << name << '\t'<<'\t' << id << '\t' << '\n';
		}
		fin.close();
	}

};
#endif // !SELLER_H
