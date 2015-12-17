#pragma once

#include <iostream>

using namespace std;

class Vector {
	double *vector;
	int size;
public:
	Vector(int, double);
	Vector();
	Vector(const Vector &a);
	void show();
	void push(double);
	void del(int);
	int getSize() { return size; }
	Vector operator+(const Vector &a);
	Vector operator= (const Vector &a);
	int operator< (const Vector &a);
	int operator> (const Vector &a);
	double operator[](int i);
	friend ostream& operator<<(ostream& os, Vector);
};
