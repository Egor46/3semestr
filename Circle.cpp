#include "Circle.h"
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

Circle::Circle(double* c)
{
	sides = 1;
	coords = new double[3];
	for (int i = 0; i < 3; i++) {
		coords[i] = c[i];
	}
}

Circle::~Circle() {
	delete[] coords;
}

double Circle::area() const {
	return M_PI * coords[2] * coords[2];
}

double Circle::perimeter() const {
	return 2 * M_PI * coords[2];
}

void Circle::print(std::ostream& out) const {
	out << "Circle with center " << coords[0] << ' ' << coords[1] << " and radius " << coords[3] << std::endl;
}