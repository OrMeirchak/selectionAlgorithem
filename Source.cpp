#include "Header.h"
bool legalIndex(int index, int size) {
	if ((index >= size) || (index < 0)) {
		return false;
	}
	else {
		return true;
	}

}

void swapInt(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}