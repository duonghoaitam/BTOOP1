#include"Book.h"
#include<iostream>
#include"List.h"
using namespace std;
void MeNu()
{
	cout << "\n======================================--> MeNu <--======================================";
		cout << "\n1 . Hien thi danh sach.";
	cout << "\n2 . Cap nhat thong tin .";
	cout << "\n3 . Them moi .";
	cout << "\n4 . Xoa bat ki.";
	cout << "\n5 . Xoa dau.";
	cout << "\n6 . Xoa cuoi.";
	cout << "\n7. Tim Kiem . ";
	cout << "\n8 . Sap xep .";
	cout << "\n0 . Thoat .";
	cout <<
		"\n======================================================================================== = ";
}
void LuaChon()
{
	int vt;
	List list;
	if (list.getN() != 0)
		cin >> list;
	while (true)
	{
		MeNu();
		int lc;
		cout << "\nNhap vao lua chon cua ban ";
		cin >> lc;
		switch (lc)
		{
		case 1:
			cout << list;
			break;
		case 2:
			list.CapNhat();
			break;
		case 3:
			list.Them();
			break;
		case 4:
			list.XoaBatKi();
			break;
		case 5:
			list.XoaDau();
			break;
		case 6:
			list.XoaCuoi();
			break;
		case 7:
			list.TimKiem();
			break;
		case 8:
			list.SapXep();
			break;
		default:
			break;
		}
		if (lc == 0)
			break;
	}
}
int main()
{
	LuaChon();
	return 0;
}