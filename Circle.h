#pragma once
#include "Figure.h"
#include <iostream>

// x y r
class Circle : public Figure
{
public:
	Circle() { sides = 0; coords = nullptr; }
	~Circle();
	Circle(double* c);
	double area() const;
	double perimeter() const;
	void print(std::ostream& out) const;
};

