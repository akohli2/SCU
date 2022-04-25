#include<iostream>
#include<string>
#include "p2.h"

using namespace std;

int main() {
	string r1[] = {"hello", "there"};
	string r2[] = {"I", "am", "Sam"};
	tmplt<string> a(2, r1);
	tmplt<string> b(3, r2);

	a += b;
	cout << a.index(0) << endl;
	cout << a.index(1) << endl;
	cout << a.index(2) << endl;

	tmplt<string> c = (a+b);
	cout << c.index(0) << endl;
	cout << c.index(1) << endl;
	cout << c.index(2) << endl;

	cout << (a==b) << endl;

	int p1[] = {1, 2};
	int p2[] = {3, 4};
	tmplt<int> d(2, p1);
	tmplt<int> e(2, p2);

	cout << distance(d, e) << endl;

	return 0;
}