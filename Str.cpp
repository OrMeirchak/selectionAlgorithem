#include "Str.h"
Str::Str(int phSize) {
	this->phSize = phSize;
	this->logSize = 0;
	if (phSize != 0) {
		this->string = new char[phSize];
	}
	else {
		this->string = nullptr;
	}

}

Str::Str(const Str& other) {
	this->phSize = other.phSize;
	this->logSize = other.logSize;
	this->string=new char[phSize];
	memcpy(this->string, other.string, sizeof(char) * logSize);
}

Str::~Str() {
	deleteString();
}

void Str::operator=(const Str& other) {
	if (this != &other) {
		this->phSize = other.phSize;
		this->logSize = other.logSize;
		deleteString();
		this->string = new char[phSize];
		memcpy(this->string, other.string, sizeof(char) * logSize);
	}
}

void Str::deleteString() {
	if (this->string) {
		delete[] this->string;
	}
}

void Str::addChar(char ch) {
	checkMemoryAllocation();
	this->string[logSize] = ch;
	logSize++;

}

void Str::checkMemoryAllocation() {
	if (this->logSize >= this->phSize) {
		this->phSize *= 2;
		char* newString = new char[phSize];

		
		memcpy(newString, this->string, sizeof(char) * logSize);
		
		deleteString();
		this->string = newString;
}
}

void Str::clean() {
	deleteString();
	this->phSize = 2;
	this->logSize = 0;
	this->string = new char[phSize];

}

Str Str::cut(int begin, int end) const {

	Str res = Str(end - begin + 1);
	
	res.logSize = res.phSize;
	memcpy(res.string, this->string + begin, sizeof(char) * res.logSize);
	

	return res;
}

void Str::cutInChar(const char sign, Str& firstPart, Str& secondPart) const {

	int cutterIndex = firstIndexOf(sign);
	firstPart = cut(0, cutterIndex-1);
	secondPart = cut(cutterIndex + 1, logSize - 1);
    
}

int Str::firstIndexOf(const char sign) const{

	for (int i = 0; i < logSize; i++)
	{
		if (sign == string[i]) {
			return i;
		}
	}
	throw noSignFoundException(sign);
}

bool Str::negative() const {
	if (logSize > 0) {
		return (string[0] == '-');
	}
	else {
		return false;
	}
}

int Str::getLogSize() const
{
	return logSize;
}

void Str::setToPossitive() {
	if (negative()) {
		*this = cut(1, logSize - 1);
	}
}

bool Str::onlyNumbers() const {
	for (int i = 0; i < logSize; i++){
		if ((string[i] < '0') || (string[i] > '9')) {
			return false;
		}
	}
	return true;
}

double Str::setToInteger() {
	if (!onlyNumbers()) {
		throw functionThatAcceptsStringsWithNumbersOnly();
	}

	double res=0;
	int multiplier = 1;

	for (int index = logSize - 1; index >=0; index--,multiplier*=10){

		res += double(string[index]-'0') * double(multiplier);
	}

	return res;
}

double Str::setToFraction() {
	if (!onlyNumbers()) {
		throw functionThatAcceptsStringsWithNumbersOnly();
	}

	double res=0;
	double multiplier = 0.1;

	for (int index = 0; index < logSize; index++, multiplier *= 0.1) {

		res += double(string[index] - '0') * multiplier;
	}

	return res;
}

