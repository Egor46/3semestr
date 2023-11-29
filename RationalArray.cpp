#include "RationalArray.h"

RationalArray::RationalArray(const RationalArray& a) {
	length = a.length;
	arr = new Rational[length];
	for (int i = 0; i < length; i++) {
		arr[i] = a.arr[i];
	}
}

RationalArray& RationalArray::operator=(const RationalArray& other) {
	if (this == &other) return *this;
	length = other.length;
	arr = new Rational[length];
	for (int i = 0; i < length; i++) {
		arr[i] = other.arr[i];
	}
	return *this;
}

RationalArray::RationalArray(RationalArray&& other) noexcept
{
	arr = other.arr;
	length = other.length;
	other.arr = nullptr;
}

RationalArray::RationalArray(Rational* a, int n) {
	length = n;
	arr = new Rational[n];
	for (int i = 0; i < n; i++) {
		arr[i] = a[i];
	}
}

RationalArray::~RationalArray() noexcept{
	delete[] arr;
}

Rational RationalArray::operator*(const RationalArray& other) const {
	Rational result = { 0 , 1 };
	for (int i = 0; i < length; i++) {
		result += arr[i] * other[i];
	}
	return result;
}

RationalArray RationalArray::operator+(const RationalArray& other) const {
	RationalArray result{ new Rational[length], length };
	for (int i = 0; i < length; i++) {
		result[i] = arr[i] + other[i];
	}
	return result;
}

RationalArray RationalArray::operator*(const Rational& other) const
{
	RationalArray result(length);
	for (int i = 0; i < length; i++) {
		result[i] = arr[i] * other;
	}
	return result;
}

RationalArray& RationalArray::operator+=(const RationalArray& other)
{
	for (int i = 0; i < length; i++) arr[i] += other[i];
	return *this;
}

RationalArray& RationalArray::operator*=(const Rational& other)
{
	for (int i = 0; i < length; i++) {
		arr[i] = arr[i] * other;
	}
	return *this;
}

std::istream& operator>>(std::istream& in, RationalArray& a) {
	for (int i = 0; i < a.length; i++) {
		in >> a.arr[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, RationalArray& a) {
	for (int i = 0; i < a.length; i++) {
		out << a.arr[i] << ' ';
	}
	return out;
}
