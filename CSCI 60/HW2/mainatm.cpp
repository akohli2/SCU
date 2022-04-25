#include "atm.h"
#include "bankaccount.h"

#include <iostream>

int maim() {
	Atm a(300, 500);
	Atm b(400, 600);

	cout << a << endl;

	cout << (a==b) << endl;

	a+=b;

	cout << a << endl;

	a.restock(100, 100);

	cout << a << endl;

	return 0;
}