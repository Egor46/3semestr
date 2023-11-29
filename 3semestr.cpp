#pragma once
//#include <iostream>
//#include "functions.h"
//#include "CustomClass.h"
//#include "DV.h"
//#include "Parabola.h"
//#include "BankAccount.h"
//#include "Rational.h"
//#include "BoolFunction.h"
//#include "IntArray.h"
//#include "Array.h"
//#include "RationalArray.h"
//#include "RationalMatrix.h"
#include "Rectangle.h"
#include "Circle.h"
#include "TriangleF.h"
#include "List.h"

//const int M = 10;
//using namespace std;
//
//int main() {
//	CustomClass* myArr = inputArray<CustomClass>(M);
//	printArray(myArr, M);
//	nigga(myArr, M);
//	printArray(myArr, M);
//	cout << bruh(myArr, CustomClass{ 5 }, M) << endl;
//	cout << scalarProduct(myArr, myArr, M);
//	deleteArray(myArr);
//	return 0;
//}

//int main() {
//	DV a(10, 4), b(5, 2);
//	a.setI(8);
//	std::cout << a.getI() << '\n';
//	std::cout << a.Voltage() << '\n';
//	a.SerialConnection(b);
//	std::cout << a.getR() << ' ' << a.getI();
//}

//void baS(BankAccount a) {
//	return;
//}
//
//int main() {
//	BankAccount a{ 1,"sample", 2 };
//	baS(a);
//}

//Rational* createDyn(istream& i, int n) {
//	int input;
//	Rational* massive = new Rational[n];
//	for (int b = 0; b < n; b++) {
//		i >> input;
//		massive[b].setA(input);
//		i >> input;
//		massive[b].setB(input);
//	}
//	return massive;
//}
//
//Rational scalarProduct(Rational* a, Rational* b, int n) {
//	Rational sp{ a[0].getA() * b[0].getA(), a[0].getB() * b[0].getB() };
//	for (int i = 1; i < n; i++) {
//		sp += (a[i] * b[i]);
//	}
//	return sp;
//}

//int main() {
//	int n;
//	cin >> n;
//	Rational* a = createDyn(cin, n);
//	Rational* b = createDyn(cin, n);
//	scalarProduct(a, b, n).print();
//	delarr<Rational>(a);
//	delarr<Rational>(b);
//}

//Rational** cDyn2(istream& i, int& _n) {
//	int n;
//	i >> n;
//	int i1, i2;
//	Rational** result = new Rational * [n];
//	for (int b = 0; b < n; b++) {
//		i >> i1 >> i2;
//		result[b] = new Rational{ i1,i2 };
//	}
//	_n = n;
//	return result;
//}
//
//Rational* scalarProduct2(Rational** a, Rational** b, int n) {
//	Rational* sp = new Rational{ a[0]->getA() * b[0]->getA(), a[0]->getB() * b[0]->getB() };
//	for (int i = 1; i < n; i++) {
//		sp->add(a[i]->multiplicate(*b[i]));
//	}
//	return sp;
//}
//
//int main() {
//	int n, m;
//	Rational** a = cDyn2(cin, n);
//	Rational** b = cDyn2(cin, m);
//	Rational* s = scalarProduct2(a, b, n);
//	s->print();
//	delete s;
//	for (int i = 0; i < n; i++) {
//		delete a[i];
//		delete b[i];
//	}
//	delete[] a;
//	delete[] b;
//}

//int main() {
//	int* ba = new int[5];
//	for (int i = 0; i < 5; i++) std::cin >> ba[i];
//	IntArray a(5), b(ba, 5);
//	cout << a.scalarProduct(b);
//	delete[] ba;
//}

//int main() {
//	Rational r1{ 1,2 }, r2{2,3};
//	r1.print(); r2.print();
//	Rational r3 = r1 + r2;
//	std::cout << "r3 "; r3.print();
//	std::cout << "r3+=r1 "; r3 += r1;
//	r3.print();
//	std::cout << "r1*r2 "; (r1 * r2).print();
//	std::cout << "r2 *= r3 "; r2 *= r3;
//	r2.print();
//	std::cout << "r1 = r2 / r3 - r1 "; r1 = r2 / r3 - r1;
//	r1.print();
//	std::cout << "r2 = r1++ / r3 "<< r1.getA() << '/' << r1.getB() << ' ' << r3.getA() << '/' << r3.getB() << ' ';
//	r2 = r1++ / r3;
//	r2.print();
//	std::cout << "r2 = ++r1 / r3 "; r2 = ++r1 / r3;
//	r2.print();
//}

//int main() {
//	Rational* r1 = new Rational[3];
//	Rational* r2 = new Rational[3];
//	RationalArray arr1{ r1, 3 }, arr2{ r2, 3 };
//	cin >> arr1; cin >> arr2;
//	Rational result = arr1 * arr2;
//	cout << result << endl;
//	RationalArray result2 = arr1 + arr2;
//	cout << result2 << endl;
//	delete[] r1; delete[] r2;
//}

//int main() {
//	int n; cin >> n;
//	Array<int> arr(n);
//	cin >> arr;
//	Array<int> arr2(n);
//	cin >> arr2;
//	cout << arr;
//	cout << arr*arr2;
//}

//int main() {
//	int figurecount;
//	cin >> figurecount;
//	Figure** figures = new Figure * [figurecount];
//	double* a;
//	for (int i = 0; i < figurecount; i++) {
//		char c; cout << "Enter figure type(c-circle, r-rect, t-triangle): "; cin >> c;
//		switch (c) {
//		case 'c':
//			a = new double[3];
//			cout << "Enter center coord: ";
//			cin >> a[0] >> a[1];
//			cout << "Enter radius: ";
//			cin >> a[2];
//			figures[i] = new Circle(a);
//			delete[] a;
//			break;
//		case 'r':
//			a = new double[4];
//			cout << "Enter 2 opposite points: ";
//			for (int i = 0; i < 4; i++) {
//				cin >> a[i];
//			}
//			figures[i] = new Rectangle(a);
//			delete[] a;
//			break;
//		case 't':
//			cout << "Enter 3 points: ";
//			a = new double[6];
//			for (int i = 0; i < 6; i++) {
//				cin >> a[i];
//			}
//			figures[i] = new TriangleF(a);
//			delete[] a;
//			break;
//		}
//	}
//	//task 2 3
//	double minp = figures[0]->perimeter(), maxa = figures[0]->area();
//	for (int i = 1; i < figurecount; i++) {
//		double a = figures[i]->perimeter(), b = figures[i]->area();
//		minp = minp > a ? a : minp; maxa = b > maxa ? b : maxa;
//	}
//	cout << "Min perimeter: " << minp << "\nMax area: " << maxa;
//	for (int i = 0; i < figurecount; i++) delete figures[i]; delete[] figures;
//}

//int main() {
//	List<int> a;
//	cin >> a;
//	List<double> b;
//	cin >> b;
//	a.addBeforeCur(2);
//	b.next();
//	b.addAfterCur(3);
//	cout << a << endl << b;
//}

int main() {

}