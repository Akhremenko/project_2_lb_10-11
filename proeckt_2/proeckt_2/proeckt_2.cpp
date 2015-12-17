// proeckt_2.cpp: определяет точку входа для консольного приложения.

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
		v.push_back(a); //вставляем а с конца в v1 и в v
		v1.push_back(a);
		cout << v[i] << " ";
	}

	vector<Vector>::iterator p = v.begin(); //для вектора v создаем итератор на начало вектора
	//p += 2;

	v.erase(p);   //удаляем первый элемент вектора
	p = v.begin();//p присваиваем значение новой вершины
	*p = a1;   // замена 2 на 111 (2)
	v.insert(p + 1, 2, a2);//добавляем элементы в вектор
	v.insert(p + 2, a3); 
						
	cout << "\n Vstavka, udalenie. V\n";

	p = v.begin();//присваиваем p значение вершины вектора 
	while (p != v.end())  //(3)
	{
		cout << *p << " ";
		p++;
	}
	cout << "\nudalenie. V\n";
	p = v.begin();

	v.erase(p + 2, p + 5);//удаляем все элементы от p+2 до p+5


	p = v.begin();
	while (p != v.end())  //(3)
	{
		cout << *p << " ";
		p++;
	}
	cout << "\nVstavka v1. V\n";
	v.insert(v.begin() + 2, v1.begin(), v1.end()); // вставляем в v с позиции (3) все элементы вектора v1

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