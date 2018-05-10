#include "var.h"

int main() {
	var a = 25.5;
	var c = a + "12.5";
	
	a.show();
	cout << endl;
	c.show();

	system("pause");
	return 0;
}