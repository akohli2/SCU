#include "biguint.h"

#include <iostream>

using namespace std;

int main() {
	biguint b1("50");
	biguint b2("10");

	biguint b3 = b1+b2;
	cout << b3 << endl; 

	cout << (b1.compare(b2)) << endl; 
	cout << (b1<b2) << endl; 
	cout << (b1<=b2) << endl; 
	cout << (b1!=b2) << endl; 
	cout << (b1==b2) << endl; 
	cout << (b1>=b2) << endl;
	cout << (b1>b2) << endl;

	b1-=b2;
	cout << b1 << endl;

	biguint b4 = b1-b2;
	cout << b4 << endl;

	string s = b1.toString();
	cout << s << endl;
}