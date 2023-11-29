#include "Rational.h"

int Rational::NOD() const
{
	int n = a;
	int d = b;
	while (n != 0 && d != 0)
		if (abs(n) > abs(d))
			n %= d;
		else
			d %= n;
	return n + d;
}

void Rational::reduce()
{
	int nod = NOD();
	a /= nod;
	b /= nod;
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
	reduce();
}

Rational::Rational(const Rational& c)
{
	a = c.a;
	b = c.b;
	reduce();
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
	reduce();
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
	reduce();
	return *this;
}

Rational Rational::operator/(const Rational& other)
{
	return Rational(a * other.b, b * other.a);
}

Rational& Rational::operator/=(const Rational& other)
{
	a *= other.b; b *= other.a;
	reduce();
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
