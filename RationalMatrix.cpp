#include "RationalMatrix.h"

RationalMatrix::RationalMatrix() :n(0), matrix(nullptr)
{
}

RationalMatrix::~RationalMatrix() {
	//delete[] matrix;
}

RationalMatrix::RationalMatrix(const RationalMatrix& other) : n(other.n), matrix(new RationalArray[other.n])
{
	for (int i = 0; i < n; i++) matrix[i] = other.matrix[i];
}

RationalMatrix::RationalMatrix(const RationalArray* other, int n) : n(n), matrix(new RationalArray[n])
{
	for (int i = 0; i++; i < n) matrix[i] = other[i];
}


RationalMatrix::RationalMatrix(RationalMatrix&& other) noexcept
{
	matrix = other.matrix;
	n = other.n;
	other.matrix = nullptr;
}

RationalMatrix& RationalMatrix::operator=(const RationalMatrix& other)
{
	if (this == &other) return *this;
	n = other.n;
	matrix = new RationalArray[n];
	for (int i = 0; i < n; i++) matrix[i] = other.matrix[i];
	return *this;
}

RationalMatrix& RationalMatrix::operator=(RationalMatrix&& other) noexcept
{
	n = other.n;
	matrix = other.matrix;
	other.matrix = nullptr;
	return *this;
}

Rational RationalMatrix::trace() const
{
	Rational result;
	for (int i = 0; i < n; i++) result += matrix[i][i];
	return result;
}

RationalMatrix RationalMatrix::operator+(const RationalMatrix& other) const
{
	RationalMatrix result(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) result[i][j] = matrix[i][j] + other.matrix[i][j];
	}
	return result;
}

RationalMatrix& RationalMatrix::operator+=(const RationalMatrix& other)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) matrix[i][j] = other.matrix[i][j];
	}
	return *this;
}

RationalMatrix RationalMatrix::operator*(const RationalMatrix& other) const
{
	RationalMatrix result(other.n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i] += other[j] * matrix[i][j];
		}
	}
	return result;
}

std::istream& operator >> (std::istream& in, RationalMatrix& m) {
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
			in >> m[i][j];
		}
	}
	return in;
}

std::ostream& operator << (std::ostream& out, const RationalMatrix& m) {
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
			out << m[i][j] << '\t';
		}
		out << std::endl;
	}
	return out;
}