#include "Book.h"
#include<iomanip>
#include<string>
#include<iostream>
using namespace std;
Book::Book()
{
}
Book::~Book()
{
}
void Book::setMa(string ma)
{
	this->ma = ma;
}
void Book::setTen(string ten)
{
	this->ten = ten;
}
void Book::setNamXB(int nam)
{
	this->namXB = nam;
}
void Book::setSoQuyen(int sq)
{
	this->soQ = sq;
}
void Book::setTinhTrang(bool tt)
{
	this->TinhTrang = tt;
}
string Book::getMa()
{
	return this->ma;
}
string Book::getTen()
{
	return this->ten;
}
int Book::getNamXB()
{
	return this->namXB;
}
int Book::getSoQuyen()
{
	return this->soQ;
}
bool Book::getTinhTrang()
{
	return this->TinhTrang;
}
istream & operator >> (istream & is, Book & s)
{
	int kt;
	do {
		kt = 0;
		cout << "\nNhap ma : ";
		getline(is, s.ma);
		if (s.ma.length() != 9)
		{
			kt = 1;
		}
		else {
			if (s.ma[0] > '9' || s.ma[0] < '1')
				kt = 1;
			for (int i = 1; i < 9; i++)
			{
				if (s.ma[i] > '9' || s.ma[i] < '0')
				{
					kt = 1;
					break;
				}
			}
		}
	} while (kt == 1);
	cout << "\nNhap ten : ";
	getline(is, s.ten);
	int namxb;
	do {
		cout << "\nNhap nam xb : ";
		cin >> namxb;
	} while (namxb < 1000 || namxb > 2018);
	s.namXB = namxb;
	cout << "\Nhap so quyen : ";
	cin >> s.soQ;
	int tt;
	do {
		cout << "\Nhap tt : ";
		cin >> tt;
	} while (tt != 0 && tt != 1);
	s.TinhTrang = tt;
	return is;
}
ostream & operator<<(ostream & out, const Book & s)
{
	string tt;
	if (s.TinhTrang == 0)
		tt = " Het!";
	if (s.TinhTrang == 1)
		tt = "Con";
	out << setw(20) << s.ma << setw(20) << s.ten << setw(15) << s.namXB << setw(15) <<
		s.soQ << setw(15) << tt << endl;
	return out;
}