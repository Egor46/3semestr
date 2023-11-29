#include "TriangleF.h"

double metric(double* d1, double* d2) {
	double p = 0;
	for (int i = 0; i < 2; i++) p += pow(d1[i] - d2[i], 2);
	return sqrt(p);
}

TriangleF::~TriangleF()
{
	delete[] coords;
}

TriangleF::TriangleF(double* c) {
	coords = new double[6];
	for (int i = 0; i < 6; i++) {
		coords[i] = c[i];
	}
}

double TriangleF::perimeter() const {
	return metric(coords, coords + 2) + metric(coords + 2, coords + 4) + metric(coords, coords + 4);
}

void TriangleF::print(std::ostream& out) const
{
	out << "Triangle with vertexes ";
	for (int i = 0; i < 3; i++) {
		out << '(' << coords[2 * i] << coords[2 * i + 1] << ") ";
	} out << '\n';
}

double TriangleF::area() const {
	double p = perimeter()/2;
	double a = p * (p - metric(coords, coords+2)) * (p - metric(coords+2, coords + 4)) * (p - metric(coords, coords + 4));
	return sqrt(a);
}
