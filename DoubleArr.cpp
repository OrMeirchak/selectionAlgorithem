#include <iostream>
using namespace std;
#include "DoubleArr.h"
DoubleArr::DoubleArr(int size){
	if (size < 0) {
		throw "wrong input";
	}
	this->size = size;
	if (size) {
		arr = new double[size];
	}
	else {
		arr = nullptr;
	}
}

DoubleArr::DoubleArr(const DoubleArr& other){
	this->size = other.size;
	arr = new double[size];
	memcpy(arr, other.arr, sizeof(double)*size);
}

DoubleArr::~DoubleArr(){
	delete []arr;
}

int DoubleArr::getSize() const
{
	return size;
}

DoubleArr DoubleArr::cut(int begin, int end) {
	DoubleArr res(end - begin + 1);

	memcpy(res.arr, arr + begin, sizeof(double)*res.size);

    return res;
	
}

void DoubleArr::getUserInput(){
	cin.ignore();
	char ch='0';
	int index=0;
	Str num;
	while (ch != '\n') {
		num.clean();
		ch = getchar();
		while ((ch != ' ') && (ch != '\n')) {
			num.addChar(ch);
			ch = getchar();
		}
		
		if (legalIndex(index, size)) {
			arr[index] = setToDouble(num);
		}
		else {
			throw "wrong input";
		}
		
		index++;
	}

	if (index != size) {
		throw "wrong input";
	}

}

void DoubleArr::swap(int index1, int index2){
	if (!legalIndex(index1,size)) {
		throw indexException(index1);
	}
	else if (!legalIndex(index2,size)) {
		throw indexException(index2);
	}
	else {
		double temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

void DoubleArr::printDouble(int index) const{
	if (!legalIndex(index, size)) {
		throw indexException(index);
	}
	
	int integer = arr[index];

	double fraction = arr[index] - integer;

	fraction = fraction * 10000;
	if ((integer == 0) && (fraction < 0)) {
		cout << '-';
	}
	cout << integer << "." << absoluteValue(fraction);
	if (fraction == 0) {
		cout << "000";
	}
	cout << endl;
}

