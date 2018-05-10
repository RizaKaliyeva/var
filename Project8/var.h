#pragma once
#include "library.h"

class var {
private:
	int intV;
	double doubleV;
	char stringV[500];
	bool intFlag = false;
	bool doubleFlag = false;
	bool stringFlag = false;

public:
	var() { intFlag = false; doubleFlag = false; stringFlag = false; };
	var(int intV);
	var(double doubleV);
	var(const char* stringV);
	operator int();
	operator double();
	operator const char*();
	var operator+(int v);
	var operator+(double v);
	var operator+(const char* v);

	void show();

};
