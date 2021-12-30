#include "Van.h"
#include "Automobile.h"

#include <iostream>

using namespace std;

Van::Van(): Automobile() {
	seats = 0;
}

Van::Van(std::string make_, std::string model_, int year_, int price_, int stall_, int s): Automobile(make_, model_, year_, price_, stall_){
	seats = s;
}

bool Van::park(bool lot[], int size) {
	if (seats_() < 7) {
		Automobile::park(lot, size);
	} else {
		int spot = size;
		for (int i = 0; i < size-1; i++) {
			if (lot[i] == false && lot[i+1] == false) {
				spot = i;
			}
		}
		if (spot >= size) {
			return false;
		} else {
			lot[spot] = true;
			lot[spot+1] = true;
			Automobile::set_stall(spot);
			return true;
		}
	}
}