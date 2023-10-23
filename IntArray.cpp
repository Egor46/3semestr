#include "IntArray.h"

IntArray::IntArray()
{
	length = 0;
	arr = nullptr;
}

IntArray::IntArray(const int* a, int n)
{
	length = n;
	arr = new int[length];
	for (int i = 0; i < n; i++) {
		arr[i] = a[i];
	}
}

IntArray::IntArray(int n)
{
	length = n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

IntArray::IntArray(const IntArray& other) {
	length = other.length;
	arr = new int[length];
	for (int i = 0; i < length; i++) {
		arr[i] = other.arr[i];
	}
}

IntArray::~IntArray() noexcept
{
	delete[] arr;
}

int IntArray::operator*(const IntArray& other) const
{
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i] * other.arr[i];
	}
	return sum;
}

void IntArray::print() const
{
	for (int i = 0; i < length; i++) {
		std::cout << arr[i];
	}
}

int& IntArray::operator[](int n) {
	return arr[n];
}
