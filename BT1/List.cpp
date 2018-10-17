#include "List.h"
#include<iomanip>
List::List()
{
	cout << "\nNhap n : ";
	cin >> n;
	data = new Book[n];
}
List::~List()
{
	delete[]data;
}
int List::getN()
{
	return this->n;
}
void List::ThemDau(Book s)
{
	Book*b = new Book[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = data[i];
	}
	delete[]data;
	data = new Book[n + 1];
	for (int i = 1; i < n + 1; i++)
	{
		data[i] = b[i - 1];
	}
	delete[]b;
	data[0] = s;
	n = n + 1;
}
void List::Themcuoi(Book s)
{
	Book *b = new Book[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = data[i];
	}
	delete[]data;
	data = new Book[n + 1];
	for (int i = 0; i < n; i++)
	{
		data[i] = b[i];
	}
	delete[]b;
	data[n] = s;
	n = n + 1;
}
void List::ThemBatKi(Book s)
{
	int vt;
	do {
		cout << "\nNhap vi tri can them ";
		cin >> vt;
		if (vt < 0 || vt > n - 1)
		{
			cout << "\nVi tri ban muon them phai > 0 va < " << n - 1;
		}
	} while (vt < 0 || vt >n - 1);
	Book *b = new Book[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = data[i];
	}
	delete[]data;
	data = new Book[n + 1];
	for (int i = n; i >= 0; i--)
	{
		if (i > vt)
		{
			data[i] = b[i - 1];
		}
		else if (i == vt)
		{
			data[vt] = s;
		}
		else {
			data[i] = b[i];
		}
	}
	delete[]b;
	n = n + 1;
}
void List::Them()
{
	Book s;
	int vt;
	int kt = 0;
	cout << "\nNhap sach ban muon them : ";
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (data[i].getMa() == s.getMa() && data[i].getTen() == s.getTen() &&
			data[i].getNamXB() == s.getNamXB())
		{
			data[i].setSoQuyen(data[i].getSoQuyen() + s.getSoQuyen());
			data[i].setTinhTrang(data[i].getTinhTrang() || s.getTinhTrang());
			kt = 1;
			break;
		}
	}
	if (kt == 0)
	{
		cout << "\nban hay nhap vao vi tri muon them ";
		cout << "\n1 . them vao dau ds \n 2. them vao cuoi danh sach \nsokhac.them vao vi	tri bat ki ";
			cin >> vt;
		if (vt == 1)
			ThemDau(s);
		else if (vt == 2)
			Themcuoi(s);
		else
			ThemBatKi(s);
	}
}
bool TangDan(float a, float b)
{
	return a > b;
}
bool GiamDan(float a, float b)
{
	return a < b;
}
void List::MergeSort(Book * p, int n, bool ComFunct(float, float))
{
	int h = 1, i, j, c = 0;
	Book x;
	while (h <= n / 3)
	{
		h = h * 3 + 1;
	}
	while (h > 0)
	{
		for (i = h; i < n; i++)
		{
			x = p[i];
			j = i;
			while (ComFunct(p[j - h].getNamXB(), x.getNamXB()) && j > h - 1)
			{
				p[j] = p[j - h];
				j -= h;
			}
			p[j] = x;
		}
		h = (h - 1) / 3;
	}
}
void List::SapXep()
{
	int lc;
	cout << "\nNhap vao lua chon sap xep cua ban . 1 tang dan , 2 giam dan . ";
	cin >> lc;
	if (lc == 1)
	{
		MergeSort(data, n, TangDan);
	}
	if (lc == 2)
	{
		MergeSort(data, n, GiamDan);
	}
}
void List::XoaDau() {
	Book*b = new Book[n]; 
	for (int i = 0; i < n; i++) {
		b[i] = data[i];
	}  delete[]data; 
	data = new Book[n - 1]; 
	n = n - 1;
	for (int i = 1; i < n ; i++)
	{ data[i] = b[i + 1]; }  
	delete[]b; 
}

void List::XoaCuoi() { 
	Book *b = new Book[n]; 
	for (int i = 0; i < n; i++)
	{ b[i] = data[i]; }  
	delete[]data; 
	data = new Book[n - 1];
	n = n - 1;  
	for (int i = 0; i < n; i++)
	{
		data[i] = b[i];
	}
	delete[]b; }


void List::XoaBatKi() {
	int vt;
	do{
	cout << "\nNhap vi tri de xoa";
	cin >> vt;
	if (vt < 0 || vt>n -1) { cout << "\n Vi tri ban mon xoa phai>0 va<" << n - 1; }
}while (vt > 0 || vt < n - 1);
	Book *b = new Book[n]; 
	for (int i = 0; i < n; i++) 
	{
		b[i] = data[i];
	}
	delete[]data;
	data = new Book[n - 1];  for (int i = 0; i < n; i++)
	{ 
		if (i < vt) {
			data[i] = b[i]; }
		else if (i == vt) 
		{
			continue; }
		else { 
			data[i-1] = b[i]; } 
	}  
	delete[]b; 
	n = n - 1;

}
void List::TimKiem()
{
	int m = 0;
	Book *p = NULL;
	MergeSort(data, n, TangDan);
	int N;
	int Lo = 0, Hi = n - 1, Mid = -1;
	cout << "\nNhap vao nam ban muon tim kiem : ";
	cin >> N;
	while (Lo != Hi && N >= data[Lo].getNamXB() && N <= data[Hi].getNamXB())
	{
		Mid = Lo + (Hi - Lo) * (N - data[Lo].getNamXB()) / (data[Hi].getNamXB() -
			data[Lo].getNamXB());
		if (data[Mid].getNamXB() < N)
			Lo = Mid + 1;
		else if (data[Mid].getNamXB() > N)
			Hi = Mid - 1;
		else
			break;
	}
	if (data[Lo].getNamXB() == N)
	{
		Mid = Lo;
	}
	if (Mid != -1)
	{
		m++;
		p = new Book[1];
		p[0] = data[Mid];
		int Mid1 = Mid - 1, Mid2 = Mid + 1;
		while (Mid1 >= 0)
		{
			if (data[Mid1].getNamXB() == N)
			{
				Book *q;
				q = new Book[m];
				for (int i = 0; i < m; i++)
				{
					q[i] = p[i];
				}
				p = new Book[m + 1];
				for (int i = 0; i < m; i++)
				{
					p[i] = q[i];
				}
				delete[]q;
				p[m] = data[Mid1];
				m++;
				Mid1--;
			}
			else
				break;
		}
		while (Mid2 < n)
		{
			if (data[Mid2].getNamXB() == N)
			{
				Book *q;
				q = new Book[m];
				for (int i = 0; i < m; i++)
				{
					q[i] = p[i];
				}
				p = new Book[m + 1];
				for (int i = 0; i < m; i++)
				{
					p[i] = q[i];
				}
				delete[]q;
				p[m] = data[Mid2];
				m++;
				Mid2++;
			}
			else
				break;
		}
	}
	if (p == NULL)
	{
		cout << "\nKhong ton tai sach co nam xuat ban nhu tren trong danh sach";
	}
	else {
		cout << setw(20) << "Ma Sach" << setw(20) << "Ten Sach" << setw(15) << "NamXB" << setw(15) << "So Quyen" << setw(15) << "Tinh Trang" << endl;
			for (int i = 0; i < m; i++)
			{
				cout << p[i] << endl;
			}
	}
	delete[]p;
}
void List::CapNhat()
{
	Book s;
	string ten;
	cout << "\nNhap ten sach ban muon cap nhat : ";
	getline(cin, ten);
	for (int i = 0; i < n; i++)
	{
		if (data[i].getTen() == ten)
		{
			cout << "\Nhap thong tin sach cap nhat .";
			cin >> s;
			data[i].setMa(s.getMa());
			data[i].setTen(s.getTen());
			data[i].setNamXB(s.getNamXB());
			data[i].setSoQuyen(s.getSoQuyen());
			data[i].setTinhTrang(s.getTinhTrang());
		}
	}
}
Book & List::operator[](int i)
{
	return data[i];
}
ostream & operator<<(ostream & out, const List & List)
{
	out << setw(20) << "Ma Sach" << setw(20) << "Ten Sach" << setw(15) << "Nam XB" <<setw(15) << "So Quyen" << setw(15) << "Tinh Trang" << endl;
	for (int i = 0; i < List.n; i++)
	{
		out << List.data[i] << endl;
	}
	return out;
}
istream & operator >> (istream & is, const List & List)
{
	for (int i = 0; i < List.n; i++)
	{
		is >> List.data[i];
	}
	return is;
}