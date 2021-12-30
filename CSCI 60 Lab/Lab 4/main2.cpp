#include "dbiguint.h"

#include <iostream>

using namespace std;

int main() {
	dbiguint b1("2000");
	dbiguint b2("90000");

	// cout << b1.size() << endl;

	// cout << b1[0] << endl;
	// cout << b1 << endl;

	// b1.reserve(8);

	// cout << b1 << endl;

	// b1+=b2;
	// cout << b1 << endl;





	// cout << (b1.compare(b2)) << endl; 

	dbiguint b3 = (b1+b2);
	cout << b3 << endl; 

	cout << (b1<b2) << endl; //1
	cout << (b1<=b2) << endl; //1
	cout << (b1!=b2) << endl; //1
	cout << (b1==b2) << endl; //0
	cout << (b1>=b2) << endl;//0
	cout << (b1>b2) << endl; //0

	return 0;
}