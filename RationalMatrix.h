#pragma once
#include "RationalArray.h"

class RationalMatrix
{
	friend std::istream& operator>>(std::istream& in, RationalMatrix& m);
	friend std::ostream& operator<<(std::ostream& out, const RationalMatrix& m);
private:
	int n;
	RationalArray* matrix;
public:
	RationalMatrix();
	~RationalMatrix();
	RationalMatrix(const RationalMatrix& other);
	RationalMatrix(const RationalArray* other, int n);
	RationalMatrix(RationalMatrix&& other) noexcept;
	RationalMatrix& operator=(const RationalMatrix& other);
	RationalMatrix& operator=(RationalMatrix&&) noexcept;
	RationalMatrix(const int size) {
		n = size;
		matrix = new RationalArray[size];
		for (int i = 0; i < n; i++) {
			matrix[i] = RationalArray(size);
		}
	}

	RationalArray& operator[](int i) const {
		return matrix[i];
	}
	int size() const { return n; }
	Rational trace() const;

	RationalMatrix operator+(const RationalMatrix& other) const;
	RationalMatrix& operator+=(const RationalMatrix& other);

	RationalMatrix operator*(const RationalMatrix& other) const;
};

