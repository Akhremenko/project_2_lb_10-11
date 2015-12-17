#include "stdafx.h"
#include "Vectr.h"

Vector::Vector() //конструктор без параметров
{
	vector = NULL;
	size = 0;
}

Vector::Vector(const Vector & a) //конструктор копирования 
{
	vector = new double[a.size]; //выделяем память под массив размером a.size
	size = a.size;
	for (int i(0);i < a.size;i++)
	{
		vector[i] = a.vector[i];
	}
}

void Vector::show() //вывод вектора
{
	std::cout << "( ";
	for (int i(0);i < size; i++) //выводим элементы поочередно
	{
		std::cout << vector[i];
		if (i != size - 1)
			std::cout << " , ";
	}
	std::cout << " )\n";
}

void Vector::push(double x) //вставка новых элементов
{
	if (vector == NULL)
	{
		size = 1;
		vector = new double[size];
		vector[0] = x;
		return;
	}

	double *a = new double[size];
	for (int i(0);i< size;i++)
		a[i] = vector[i];
	delete (vector);
	vector = new double[size + 1];
	for (int i(0);i< size;i++)
		vector[i] = a[i];
	vector[size] = x;
	size++;
}

void Vector::del(int index) // удаление с указанной позиции по последний эл-т
{
	for (int i = index; i < size - 1; i++)
	{
		vector[i] = vector[i + 1];
	}
	size--;
	double *a = new double[size];
	for (int i(0);i< size;i++)
		a[i] = vector[i];
	delete (vector);
	vector = new double[size];
	for (int i(0);i< size;i++)
		vector[i] = a[i];
}

Vector Vector::operator+(const Vector & a) // сложение двух векторов
{
	Vector tmp;
	if (size == a.size) 
	{
		tmp.size = size;
		tmp.vector = new double[tmp.size];
		for (int i(0);i < size;i++) 
		{
			tmp.vector[i] = vector[i] + a.vector[i];
		}
		return tmp;
	}
	else {
		std::cout << "\nsize_1 != size_2\n";
		return tmp;
	}
}

Vector Vector::operator=(const Vector & a)
{
	if (vector != NULL)
		delete(vector);

	vector = new double[a.size];

	for (int i(0); i < a.size; i++)
	{
		vector[i] = a.vector[i]; // копируем один вектор в новый(ПУСТОЙ) вектор
	}
	size = a.size;
	return *this;
}

int Vector::operator<(const Vector & a)
{
	return size<a.size;
}

int Vector::operator>(const Vector & a)
{
	return size>a.size;
}

double Vector::operator[](int i)
{
	return vector[i];
}

Vector::Vector(int N, double a)
{
	size = N;
	vector = new double[N];
	for (int i(0); i < N;i++) //создаем вектор размеров N в который каждому элементу присваиваем значение a
	{
		vector[i] = a;
	}
}

ostream& operator<<(ostream& os, Vector v) 
{
	v.show();
	return os;
}