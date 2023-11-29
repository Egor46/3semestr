#pragma once
#include "Figure.h"
class Rectangle : public Figure
{
public:
	Rectangle() { sides = 0; coords = nullptr; };
	~Rectangle();
	Rectangle(double* c);

	double area() const;
	double perimeter() const;
	void print(std::ostream& out) const;
};

