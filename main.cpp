#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Sort.h"
int main() {
	int size;
	int element;
	
	cin >> size;
	cin >> element;
	try {
		DoubleArr arr(size);
		cin>>arr;
			Sort sort;
			sort(arr, element);
	}
	catch (const char* msg) {
		cout << "wrong input";
	}
	catch (exception& e) {
		cout << "wrong input";
	}
}
