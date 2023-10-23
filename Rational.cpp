#include "Rational.h"

static int nod(int, int);

void Rational::ease()
{
	int C = nod(a, b);
	a = a / C;
	b = b / C;
}

Rational::Rational()
{
	a = 0;
	b = 1;
}

Rational::Rational(int _a, int _b)
{
	a = _a;
	b = _b;
	ease();
}

Rational::Rational(const Rational& c)
{
	a = c.a;
	b = c.b;
	ease();
}

Rational& Rational::operator=(const Rational& other)
{
	a = other.a;
	b = other.b;
	return *this;
}

void Rational::setA(int _a)
{
	a = _a;
}

void Rational::setB(int _b)
{
	b = _b;
}

int Rational::getA() const
{
	return a;
}

int Rational::getB() const
{
	return b;
}

//void Rational::add(Rational c)
//{
//	a = a * c.b + b * c.a;
//	b = b * c.b;
//	ease();
//}

//Rational Rational::multiplicate(Rational c, bool easeResult) const
//{
//	Rational res;
//	res.a = (c.a * a);
//	res.b = (c.b * b);
//	if (easeResult) res.ease();
//	return res;
//}

void Rational::print() const
{
	std::cout << a << '/';
	if (b < 0) std::cout << '(' << b << ')';
	else std::cout << b;
	std::cout << '\n';
}

Rational& Rational::operator+=(const Rational& c)
{
	a = a * c.b + b * c.a;
	b = b * c.b;
	ease();
	return *this;
}

Rational Rational::operator+(const Rational& other)
{
	return Rational(a * other.b + b * other.a, b * other.b);
}

Rational Rational::operator-(const Rational& other)
{
	return Rational(a * other.b - b * other.a, b * other.b);
}

Rational& Rational::operator-=(const Rational& other) {
	a -= other.a;
	b -= other.b;
	ease();
	return *this;
}

Rational Rational::operator/(const Rational& other)
{
	return Rational(a * other.b, b * other.a);
}

Rational& Rational::operator/=(const Rational& other)
{
	a *= other.b; b *= other.a;
	ease();
	return *this;
}

Rational& Rational::operator++()
{
	a += b;
	return *this;
}

Rational Rational::operator++(int) {
	Rational n(*this);
	a += b;
	return n;
}

static int nod(int numerator, int denominator)
{
	if (numerator < denominator) {
		int t = numerator;
		numerator = denominator;
		denominator = t;
	}
	int mult = 0, t;
	while (denominator) {
		mult = 0;
		while (numerator >= denominator) {
			numerator -= denominator;
			mult++;
		}
		t = numerator;
		numerator = denominator;
		denominator = t;
	}
	return numerator > 0 ? numerator : 1;
}

Rational& operator*=(Rational& left, const Rational& right) {
	left.setA(left.getA() * right.getA());
	left.setB(left.getB() * right.getB());
	return left;
}

Rational operator*(const Rational& left, const Rational& right)
{
	return Rational(left.a * right.a, left.b * right.b);
}

std::istream& operator>>(std::istream& in, Rational& r)
{
	in >> r.a >> r.b;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& r)
{
	if (r.b < 0) out << r.a << "/(" << r.b << ')';
	else out << r.a << '/' << r.b;
	return out;
}
