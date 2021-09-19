#pragma once
#include "Str.h"

class DoubleArr {
private:
	double* arr;
	int size;

	void getUserInput();

public:
	DoubleArr(int size=0);
	DoubleArr(const DoubleArr&);
	~DoubleArr();

	int getSize() const;

	DoubleArr cut(int begin, int end);

	void swap(int index1, int index2);
	void printDouble(int index) const;

	friend ostream& operator<<(ostream& os, const DoubleArr& _doubleArr) {
		os << "Array" << endl;
		for (int i = 0; i < _doubleArr.size; i++) {
			os << '[' << i << "] . ";
			_doubleArr.printDouble(i);
		}
		os << endl;
		return os;
	}
	friend istream& operator>>(istream& is, DoubleArr& _doubleArr){
			_doubleArr.getUserInput();
		return is;
	}
	double& operator[](int index) {
		if (legalIndex(index, this->size)) {
			return arr[index];
		}
		else {
			throw indexException(index);
		}
	}
	const double& operator[](int index) const {
		if (legalIndex(index, this->size)) {
			return arr[index];
		}
		else {
			throw indexException(index);
		}
	}

	static double setToDouble(Str num) {
		Str integer;
		Str fraction;
		bool neg = num.negative();
		num.setToPossitive();

		num.cutInChar('.', integer, fraction);

		if (!fraction.onlyNumbers() || !integer.onlyNumbers()||
			(integer.getLogSize()<1)||(fraction.getLogSize()>4)||(fraction.getLogSize()<1)) {
			throw "wrong input";
		}

		
		double res = fraction.setToFraction() + integer.setToInteger();
		
		if (neg) {
			res *= -1;
		}
		return res;
	}
};

