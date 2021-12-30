#include "lbiguint.h"
#include "node2.h"

#include <iostream>

using namespace std;

int main() {
	lbiguint l("1472");
	cout << l.size() << endl;
	cout << l[2] << endl;
	cout << l << endl;

	lbiguint l2("111");
	cout << l2 << endl;

	l2=l;
	cout << l2 << endl;
}