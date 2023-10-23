#include "Parabola.h"

Parabola::Parabola(double a, double b, double c)
{
	_a = a;
	_b = b;
	_c = c;
}

double Parabola::getA() const
{
	return _a;
}

double Parabola::getB() const
{
	return _b;
}

double Parabola::getC() const
{
	return _c;
}

void Parabola::setA(double a)
{
	_a = a;
}

void Parabola::setB(double b)
{
	_b = b;
}

void Parabola::setC(double c)
{
	_c = c;
}

Parabola Parabola::pCompress(double p)
{
	return Parabola(_a * p, _b * p, _c * p);
}

inline double Parabola::d() const
{
	return (2 * _a * _b) * (2 * _a * _b) - 4 * _a * (_a * _b * _b + _c);
}

void Parabola::parallelShift(double dx, double dy)
{
	_b += dx;
	_c += dy;
}

short int Parabola::isRoots()
{
	double D = (2*_a*_b) * (2*_a*_b) - 4 * _a * (_a*_b*_b+_c);
	return D < 0 ? -1 : (D == 0 ? 0 : 1);
}

double* Parabola::getRoots()
{
	if (isRoots() == 0) {
		double* a = new double;
		*a = -(2*_a*_b) / (2 * _a);
		return a;
	}
	else if (isRoots() == 1) {
		double* roots = new double[2];
		roots[0] = (-(2 * _a * _b) + d()) / (2 * _a);
		roots[1] = (-(2 * _a * _b) - d()) / (2 * _a);
		return roots;
	}
	return nullptr;
}
