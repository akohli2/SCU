#include "problem1.h"
#include <iostream>

using namespace std;

int main() {
	Rational r1 = Rational(1, 2);
	Rational r2(3, 4);
	Rational r3 = r1 + r2;
	cout << r3 << endl;
	cout << (r1==r2) << endl;
	r3+=r1;
	cout << r3 << endl;
}