#include "RationalMatrix.h"

RationalMatrix::RationalMatrix() :n(0), matrix(nullptr)
{
}

RationalMatrix::~RationalMatrix() noexcept
{
	for (int i = 0; i < n; i++) matrix[i].deletearr();
	delete[] matrix;
}

RationalMatrix::RationalMatrix(const RationalMatrix& other) : n(other.n), matrix(new RationalArray[other.n])
{
	for (int i = 0; i < n; i++) matrix[i] = other.matrix[i];
}

RationalMatrix::RationalMatrix(const RationalArray*& other, int n) : n(n), matrix(new RationalArray[n])
{
	for (int i = 0; i++; i < n) matrix[i] = other[i];
}

RationalMatrix::RationalMatrix(const RationalMatrix&& other) noexcept : n(other.n), matrix(new RationalArray[other.n])
{
	for (int i = 0; i < n; i++) {
		matrix[i] = other.matrix[i];
	}
}

RationalMatrix& RationalMatrix::operator=(const RationalMatrix& other)
{
	n = other.n;
	matrix = new RationalArray[n];
	for (int i = 0; i < n; i++) matrix[i] = other.matrix[i];
	return *this;
}

RationalMatrix& RationalMatrix::operator=(const RationalMatrix&& other)
{
	n = other.n;
	matrix = new RationalArray[n];
	for (int i = 0; i < n; i++) matrix[i] = other.matrix[i];
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
	RationalMatrix result{ new RationalArray[n], n };
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
	RationalMatrix result{new RationalArray[n], n};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i] += other[i] * matrix[i][j];
		}
	}
	return result;
}

RationalMatrix& RationalMatrix::operator*=(const RationalMatrix& other) {
	*this = *this * other;
	return *this;
}
