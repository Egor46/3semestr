#pragma once
#include "Figure.h"

class TriangleF : public Figure
{
public:
	TriangleF() { sides = 0; coords = nullptr; };
	~TriangleF();
	TriangleF(double* c);

	double area() const;
	double perimeter() const;
	void print(std::ostream& out) const;
};

