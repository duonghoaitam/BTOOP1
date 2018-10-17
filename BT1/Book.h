#pragma once
#include<string>
#include<iostream>
using namespace std;
class Book
{
private:
	string ma;
	string ten;
	int namXB;
	int soQ;
	bool TinhTrang;
public:
	Book();
	~Book();
	void setMa(string ma);
	void setTen(string ten);
	void setNamXB(int nam);
	void setSoQuyen(int sq);
	void setTinhTrang(bool tt);
	string getMa();
	string getTen();
	int getNamXB();
	int getSoQuyen();
	bool getTinhTrang();
	friend istream &operator >> (istream &is, Book &s);
	friend ostream &operator << (ostream &out, const Book &s);
};