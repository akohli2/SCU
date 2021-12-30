#include "Automobile.h"
#include <iostream>

using namespace std;

int main() {
	Automobile a1,a2("bmw", "E", 2020, 100000, 2);
	cout << a2.make() << endl;
	a2.set_stall(3);
	cout << a2.stall() << endl;
	bool lot[3] = {true, false, true};
	cout << a2.park(lot, 3) << endl;
	return 0;
}