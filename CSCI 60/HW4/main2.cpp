#include "dbiguint.h"

#include <iostream>

using namespace std;

int main() {
	dbiguint b1("5");
	dbiguint b2("100");

	dbiguint b3 = (b1*b2);
	cout << b3 << endl; 

	b1*=b2;
	cout << b1 << endl;
	
	//10500
	//10500

	return 0;
}