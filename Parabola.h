#pragma once
class Parabola
{
private:

	double _a = 0, _b = 0, _c = 0;

public:

	Parabola(double a, double b, double c);
	double getA() const; double getB() const; double getC() const;
	void setA(double a); void setB(double b); void setC(double c);
	Parabola pCompress(double p);
	inline double d() const;
	void parallelShift(double dx, double dy);
	short int isRoots();
	double* getRoots();
};