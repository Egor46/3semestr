#pragma once
#include <iostream>

class Figure
{
protected:
	int sides = 0;
	double* coords = nullptr;
public:
	virtual ~Figure() {};
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
	virtual void print(std::ostream&) const = 0;
};

