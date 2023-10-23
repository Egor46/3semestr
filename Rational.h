#pragma once
#include <iostream>

//����� �������, ��������� ������������, �������, ������� �������
//��� ���� �������������, ����������, ����� ����� ���������� �����, ������� � �������, �������� �����������, ��������� ���������, ����� �����
class Rational
{
	friend Rational operator*(const Rational& left, const Rational& right);
	friend std::istream& operator>>(std::istream& in, Rational& r);
	friend std::ostream& operator << (std::ostream& out, const Rational& r);
private:
	int a, b;
	void ease();
public:
	Rational();
	Rational(int _a, int _b);
	Rational(const Rational& c);
	Rational& operator=(const Rational& other);

	void setA(int _a); void setB(int _b); int getA() const; int getB() const;
	//void add(Rational c);
	//Rational multiplicate(Rational c, bool easeResult = true) const;
	void print() const;

	Rational& operator+=(const Rational& c);
	Rational operator+ (const Rational& other);

	Rational operator-(const Rational& other);
	Rational& operator-=(const Rational& other);

	Rational operator/(const Rational& other);
	Rational& operator /=(const Rational& other);

	Rational& operator++(); // ���������
	Rational operator++(int); // ����������
};

Rational& operator*=(Rational& left, const Rational& right);

Rational operator*(const Rational& left, const Rational& right);

