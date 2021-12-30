#ifndef PICKUP_H
#define PICKUP_H
#include "Automobile.h"

#include <iostream>

#include <string>

using namespace std;

class Pickup: public Automobile {
private:
	int hauling_capacity;
	bool extended_cab;
public: 
	int HC() {return hauling_capacity;}
	bool EC() {return extended_cab;}
	Pickup();
	Pickup(std::string make_, std::string model_, int year_, int price_, int stall_, int haul_cap, bool ext_cab);
	bool park(bool lot[], int size);

};

#endif