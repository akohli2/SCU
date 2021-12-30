#include "Van.h"
#include "Automobile.h"

#include <iostream>

#include <string>

using namespace std;

int main() {
	Van v("bmw", "E", 2020, 100000, 3, 8);

	bool lot[5] = {true, false, true, true, false};

	cout << v.park(lot, 5) << endl;
}