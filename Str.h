#pragma once
#include "Header.h"
class indexException : public exception {
private:
	int IlegalIndex;

public:

	indexException(int IlegalIndex) {
		this->IlegalIndex = IlegalIndex;
	}

	int getIlegalIndex()  const throw() {
		return IlegalIndex;
	}


};
class noSignFoundException : public exception {
private:
     char sign;
public:

	noSignFoundException(char sign) {
		this->sign = sign;
	}

	int getSign()  const throw() {
		return sign;
	}


};
class functionThatAcceptsStringsWithNumbersOnly : public exception {
};

class Str {
private:
	char* string;
	int logSize;
	int phSize;

public:
	Str(int phSize=2);
	Str(const Str&);
	~Str();
	void operator=(const Str& other);

	void deleteString();

	void addChar(char ch);

	void checkMemoryAllocation();

	void clean();

	Str cut(int begin, int end) const;

	//The function divides a string into 2 strings
	//The first string begin in index 0 and end one index before the index where the sign is located first
	//The second string begin in one index after where the sign is located first and end in logSize-1 index;
	void cutInChar(char sign, Str& firstPart, Str& secondPart) const;

	int firstIndexOf(char sign) const;

	friend ostream& operator<<(ostream& os, const Str& str) {
		os << "Str" << endl;
		for (int i = 0; i < str.logSize; i++) {
			os << str.string[i];
		}
		os << endl;
		return os;
	}

	//in case of the first char in the string is '-' the function return true
	//else the function return false
	bool negative() const;

	//in case of the first char in the string is '-' the function remove it
	void setToPossitive();

	//in case each char in the string represents a number the function return true
	bool onlyNumbers() const;

	double setToInteger();

	double setToFraction();

	//getters
	int getLogSize() const;

	char& operator[](int index) {
		if (legalIndex(index,logSize)) {
			return string[index];
		}
		else {
			throw indexException(index);
		}
	}
	const char& operator[](int index) const {
		if (legalIndex(index,logSize)) {
			return string[index];
		}
		else {
			throw indexException(index);
		}
	}
};
