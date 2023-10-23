#pragma once
#include <iostream>

using namespace std;

template<class T>
T* inputArray(int n) {
	T* arr = new T[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return arr;
}

template<class T>
void printArray(T* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return;
}

template<class T>
void nigga(T* arr, int n) {
	int j; T k;
	for (int i = 1; i < n; i++) {
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
	}
}

template<class T>
bool bruh(T* arr, T x, int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) return true;
	}
	return false;
}

template<typename T>
T scalarProduct(T* a, T* b, int n) {
	T prod = 0;
	for (int i = 0; i < n; i++) {
		prod += a[i] * b[i];
	}
	return prod;
}

template<class T>
void deleteArray(T* arr) {
	delete[] arr;
}