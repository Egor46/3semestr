#pragma once
#include <iostream>

template<class T>
class Array
{
	template<class T> friend std::istream& operator>>(std::istream& in, Array<T>& a) {
		for (int i = 0; i < a.length; i++) {
			in >> a[i];
		}
		return in;
	}
	template<class T> friend std::ostream& operator<<(std::ostream& out, Array<T> a) {
		for (int i = 0; i < a.length; i++) out << a[i] << ' ';
		cout << endl;
		return out;
	}
private:
	T* arr;
	int length;
public:

	// Special Methods

	Array() {
		length = 0;
		arr = nullptr;
	}

	Array(int n) {
		length = n;
		arr = new T[n];
	}

	~Array() noexcept {
		delete[] arr;
	}

	Array(const Array<T>& other) {
		length = other.length;
		arr = new T[length];
		for (int i = 0; i < length; i++) {
			arr[i] = other.arr[i];
		}
	}

	Array(const Array<T>&& other) : arr(nullptr), length(0) {
		if (this == &(other)) return;
		length = other.length;
		arr = new T[length];
		for (int i = 0; i < length; i++) arr[i] = other.arr[i];
		delete[] other.arr;
	}

	Array& operator=(const Array<T>& other) {
		length = other.length;
		arr = new T[length];
		for (int i = 0; i < length; i++) arr[i] = other.arr[i];
		return *this;
	}

	Array& operator=(const Array<T>&&) = delete;

	Array(T* a, int n) {
		length = n;
		arr = new T[n];
		for (int i = 0; i < n; i++) arr[i] = a[i];
	}

	// Operators

	Array<T> operator+(const Array<T>& other) const {
		Array<T> res{ new T[length], length };
		for (int i = 0; i < res.length; i++) {
			res[i] = other.arr[i] + arr[i];
		}
		return res;
	}

	Array<T>& operator+=(const Array<T>& other) {
		for (int i = 0; i < length; i++) arr[i] += other.arr[i];
		return *this;
	}

	T operator*(const Array<T>& other) const {
		T res = arr[0] * other.arr[0];
		for (int i = 1; i < length; i++) {
			res += arr[i] * other.arr[i];
		}
		return res;
	}

	T& operator[](int idx) { return arr[idx]; };

	int len() const { return length; };
};