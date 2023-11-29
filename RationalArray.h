#pragma once
#include "Rational.h"

class RationalArray
{
	friend std::istream& operator>>(std::istream& in, RationalArray& a);
	friend std::ostream& operator<<(std::ostream& out, RationalArray& a);
private:
	Rational* arr;
	int length;
public:
	RationalArray& operator=(const RationalArray& other);
	RationalArray& operator=(RationalArray&& other) noexcept {
		length = other.length;
		arr = other.arr;
		other.arr = nullptr;
		return *this;
	}
	RationalArray() { arr = nullptr; length = 0; };
	RationalArray(int n) {
		length = n; arr = new Rational[n];
		//for (int i = 0; i < n; i++) arr[i] = Rational(0, 1);
	}
	~RationalArray() noexcept;
	RationalArray(Rational* a, int n);
	RationalArray(RationalArray&& other) noexcept;
	RationalArray(const RationalArray& other);

	int len() const { return length; };

	Rational& operator[](int index) const {
		return arr[index];
	}

	Rational operator*(const RationalArray& other) const;
	RationalArray operator*(const Rational& other) const; // vector*number;
	RationalArray& operator*=(const Rational& other);
	RationalArray operator+(const RationalArray& other) const;
	RationalArray& operator+=(const RationalArray& other);
};

