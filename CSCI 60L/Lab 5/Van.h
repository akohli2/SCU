#ifndef VAN_H
#define VAN_H

#include "Automobile.h"

#include <iostream>

using namespace std;

class Van: public Automobile {
private:
	int seats;
public:
	Van();
	Van(std::string make_, std::string model_, int year_, int price_, int stall_, int s);
	int seats_() {return seats;}
	bool park(bool lot[], int size);
};

#endif