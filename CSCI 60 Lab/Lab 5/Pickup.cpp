#include "Automobile.h"
#include "Pickup.h"

#include <string>



Pickup::Pickup(): Automobile() {
	hauling_capacity = 0;
	extended_cab = false;
}

Pickup::Pickup(std::string make_, std::string model_, int year_, int price_, int stall_, int haul_cap, bool ext_cab): Automobile(make_, model_, year_, price_, stall_) {
	hauling_capacity = haul_cap;
	extended_cab = ext_cab;

}

bool Pickup::park(bool lot[], int size) {
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
		set_stall(spot);
		return true;
	}
}