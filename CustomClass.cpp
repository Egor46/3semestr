#pragma once
#include "CustomClass.h"

using namespace std;

double CustomClass::getc() {
	return comparable;
}

void CustomClass::setc(double a) {
	comparable = a;
}

CustomClass::CustomClass()
{
	comparable = 0;
}

CustomClass::CustomClass(double a)
{
	comparable = a;
}

bool CustomClass::operator<(CustomClass b)
{
	return comparable < b.getc();
}

bool CustomClass::operator>(CustomClass b)
{
	return comparable > b.getc();
}

bool CustomClass::operator==(CustomClass b)
{
	return comparable == b.getc();
}

double CustomClass::operator*(CustomClass b)
{
	return b.getc() * comparable;
}

void CustomClass::operator+=(CustomClass b)
{
	comparable += b.getc();
}

ostream& operator<<(ostream& o, CustomClass a)
{
	return o << a.getc();
}

istream& operator>>(istream& i, CustomClass& a)
{
	double b;
	i >> b;
	a.setc(b);
	return i;
}