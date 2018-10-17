#pragma once
#include"Book.h"
#include <string>
#include<iostream>
using namespace std;
class List
{
private:
	int n;
	Book *data;
public:
	List();
	~List();
	int getN();
	void ThemDau(Book s);
	void Themcuoi(Book s);
	void ThemBatKi(Book s);
	void MergeSort(Book *p, int n, bool ComFunct(float, float));
	void Them();
	void XoaDau();
	void XoaCuoi();
	void XoaBatKi();

	void SapXep();
	void TimKiem();
	void CapNhat();
	Book &operator[](int i);
	friend ostream &operator<<(ostream &out, const List &List);
	friend istream &operator>>(istream &is, const List &List);
};