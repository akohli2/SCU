#include "Automobile.h"
#include "Pickup.h"

#include <iostream>

using namespace std;

int main() {
	Pickup p2("bmw", "E", 2020, 100000, 3, 5, true);
	cout << p2.HC() << endl;

	bool lot[5] = {true, false, true, true, false};

	cout << p2.park(lot, 5) << endl; 

	return 0;
}