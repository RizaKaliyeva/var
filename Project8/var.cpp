#include "var.h"

var::var(int intV) {
	this->intV = intV;
	intFlag = true;
}
var::var(double doubleV) {
	this->doubleV = doubleV;
	this->doubleFlag = true;

}
var::var(const char* stringV) {
	stringFlag = true;
	strcpy_s(this->stringV, stringV);

}

var::operator int() {
	intFlag = true;
	doubleFlag = false;
	stringFlag = false;
	return intV;
}
var::operator double() {
	doubleFlag = true;
	intFlag = false;
	stringFlag = false;
	return doubleV;
}
var::operator const char*() {
	stringFlag = true;
	intFlag = false;
	doubleFlag = false;
	return stringV;
}

void var::show() {
	if (intFlag)
		cout << intV;
	else if (doubleFlag)
		cout << doubleV;
	else if (stringFlag)
		cout << stringV;
}

var var::operator+(int v) {
	var tmp;

	if (intFlag) {
		tmp.intFlag = true;
		tmp.intV = this->intV + v;
	}
	else if (doubleFlag)
	{
		tmp.doubleFlag = true;
		tmp.doubleV = this->doubleV + v;
	}

	else if (stringFlag)
	{
		char buf[100];
		tmp.stringFlag = true;

		//sprintf(buf,"%f",v);
		_itoa_s(v, buf, 10);
		strcpy_s(tmp.stringV, this->stringV);
		strcat(tmp.stringV, buf);

	}
	return tmp;

}

var var::operator+(double v) {
	var tmp;

	if (intFlag) {
		tmp.intFlag = true;
		tmp.intV = this->intV + v;
	}
	else if (doubleFlag)
	{
		tmp.doubleFlag = true;
		tmp.doubleV = this->doubleV + v;
	}

	else if (stringFlag)
	{
		char buf[100];
		tmp.stringFlag = true;

		sprintf(buf,"%.2f",v);
		
		strcpy_s(tmp.stringV, this->stringV);
		strcat(tmp.stringV, buf);

	}
	return tmp;
}

var var::operator+(const char* v) {
	var tmp;

	if (intFlag) {
		tmp.intV = this->intV + atoi(v);
		tmp.intFlag = true;
	}
	else if (doubleFlag) {
		tmp.doubleV = this->doubleV + atof(v);
		tmp.doubleFlag = true;
	}
	else if (stringFlag) {
		strcpy_s(tmp.stringV, this->stringV);
		strcat(tmp.stringV, v);
		tmp.stringFlag = true;
	}
	return tmp;
}