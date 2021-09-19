#pragma once
#include <iostream>
#include <string.h>
#include <chrono>
#include <fstream>
#include <iomanip>
using namespace std;
template<class T>
T absoluteValue(T temp) {
	if (temp < 0) {
		return (temp *= (-1));
	}
	else {
		return temp;
	}
}

void swapInt(int& num1, int& num2);

bool legalIndex(int index, int size);
