#include "Rectangle.h"

Rectangle::~Rectangle()
{
	delete[] coords;
}

Rectangle::Rectangle(double* c){
	sides = 4;
	coords = new double[4];
	for (int i = 0; i < 4; i++) {
		coords[i] = c[i];
	}
}

double Rectangle::area() const {
	return abs(coords[2] - coords[0]) * abs(coords[1]-coords[3]);
}

double Rectangle::perimeter() const {
	double a = abs(coords[2] - coords[0]), b = abs(coords[1] - coords[3]);
	return 2 * (a + b);
}

void Rectangle::print(std::ostream& out) const
{
	out << "Rectangle with vertexes ";
	out << '(' << coords[0] << ',' << coords[1] << ") " << '(' << coords[2] << ',' << coords[1] << ") " <<
		'(' << coords[2] << ',' << coords[3] << ") " << '(' << coords[0] << ',' << coords[3] << ") ";
}
