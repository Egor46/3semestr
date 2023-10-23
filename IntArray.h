#pragma once
#include <iostream>

class IntArray
{
private:
	int length;
	int* arr;
public:
	IntArray();

	IntArray(const int* a, int n);

	IntArray(const IntArray& other);
	
	IntArray(int n);

	~IntArray() noexcept;

	int operator*(const IntArray& other) const;

	void print() const;

	int operator[](int n) const;

	int& operator[](int n);
};

