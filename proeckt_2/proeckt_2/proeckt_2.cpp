// proeckt_2.cpp: ���������� ����� ����� ��� ����������� ����������.

#include "stdafx.h"
#include <vector>
#include "Vectr.h"
#include <iostream>

using namespace std;

int main()
{

	vector<Vector> v, v1; //(1,4)

	Vector a,a1(2,111),a2(2,222),a3(2,333);
	cout << "V\n";
	for (int i = 0;i < 5;i++)
	{
		a.push(i + 1);
		a.push(i + 2);
		v.push_back(a); //��������� � � ����� � v1 � � v
		v1.push_back(a);
		cout << v[i] << " ";
	}

	vector<Vector>::iterator p = v.begin(); //��� ������� v ������� �������� �� ������ �������
	//p += 2;

	v.erase(p);   //������� ������ ������� �������
	p = v.begin();//p ����������� �������� ����� �������
	*p = a1;   // ������ 2 �� 111 (2)
	v.insert(p + 1, 2, a2);//��������� �������� � ������
	v.insert(p + 2, a3); 
						
	cout << "\n Vstavka, udalenie. V\n";

	p = v.begin();//����������� p �������� ������� ������� 
	while (p != v.end())  //(3)
	{
		cout << *p << " ";
		p++;
	}
	cout << "\nudalenie. V\n";
	p = v.begin();

	v.erase(p + 2, p + 5);//������� ��� �������� �� p+2 �� p+5


	p = v.begin();
	while (p != v.end())  //(3)
	{
		cout << *p << " ";
		p++;
	}
	cout << "\nVstavka v1. V\n";
	v.insert(v.begin() + 2, v1.begin(), v1.end()); // ��������� � v � ������� (3) ��� �������� ������� v1

	p = v.begin();
	while (p != v.end())  //(3)
	{
		cout << *p << " ";
		p++;
	}


			p = v1.begin();
			while (p != v1.end())  //(3)
			{
				cout << *p << " ";
				p++;
			}

	return 0;
}