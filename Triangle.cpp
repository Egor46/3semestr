#include "Triangle.h"

Triangle::Triangle(double a, double b, double c)
{
	_a = a;
	_b = b;
	_c = c;
}

double Triangle::getA() const
{
	return _a;
}

double Triangle::getB() const
{
	return _b;
}

double Triangle::getC() const
{
	return _c;
}

void Triangle::setA(double a)
{
	_a = a;
}

void Triangle::setB(double b)
{
}

void Triangle::setC(double c)
{
}

double Triangle::area()
{
	double p = 1 / 2 * perimeter();
	return sqrt(p * (p - _a) * (p - _b) * (p - _c));
}

double Triangle::perimeter()
{
	return _a + _b + _c;
}

Triangle Triangle::createCongruent(double k)
{
	return Triangle(_a*k, _b*k, _c*k);
}

bool Triangle::isIsosceles()
{
	return (_a == _b) || (_a == _c) || (_b == _c);
}
