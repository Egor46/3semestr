#pragma once
#include <iostream>

class CustomClass
{
private:

	double comparable;
	
public:

	CustomClass();
	CustomClass(double);

	void someFunc()
	{
		std::cout << "someFunc()";
	}

	double getc();

	void setc(double a);

	bool operator < (CustomClass b);
	
	bool operator > (CustomClass b);

	bool operator == (CustomClass b);
	
	double operator *(CustomClass b);

	void operator +=(CustomClass b);
};

std::ostream& operator << (std::ostream& o, CustomClass a);

std::istream& operator >> (std::istream& i, CustomClass& a);