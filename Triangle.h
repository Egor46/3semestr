#pragma once
#include <math.h>

class Triangle
{
private:
	double _a=0, _b=0, _c=0;
public:

	Triangle(double a, double b, double c);
	
	double getA() const; double getB() const; double getC() const;

	void setA(double a); void setB(double b); void setC(double c);
	
	double area();

	double perimeter();

	Triangle createCongruent(double k);

	bool isIsosceles();
};

