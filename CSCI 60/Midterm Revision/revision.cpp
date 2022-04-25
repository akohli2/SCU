//1

//1, 3
//3, 3
//4, 6
//5, 4
//4, 5

//2 

void reserve(size_type new_capacity) {
	if (capacity_ < new_capacity) {
		int* new_data = new int[new_capacity];
		for (size_type i = 0; i < new_capacity; ++i) {
			new_data[i] = data_[i];
		}
		delete [] data_;
		data_ = new_data;
		capacity_ = new_capacity;
	}
}

//3

bool no_dupilicates() const {
	for (size_type i = 0;; i < capacity_; ++i) {
		for (size_type j = i+1; j < capacity_; ++j) {
			if (data_[i] == data_[j]) {
				return false;
			}
		}
	}
	return true;
}

//5

#ifndef SPORTSCAR_H
#define SPORTSCAR_H
#include "Automobile.h"

#include <iostream>
using namespace std;

class SportsCar: public Automobile {
private: 
	int octane;
	int zts;
public:
	int get_octane() {return octane;}
	int get_zts() {return zts;}
	SportsCar();
	SportsCar(string imake, string imodel, int iyear, double iprice, int istall, int octane_ , int zts_);
	bool park(bool lot[], int size);
};

SportsCar::SportsCar(): Automobile() {
	octane = 0;
	zts = 0;
}

SportsCar::SportsCar(string imake, string imodel, int iyear, double iprice, int istall, int octane_ , int zts_): Automobile(imake, imodel, iyear, iprice, istall) {
	octane = octane_;
	zts = zts_;
}

bool SportsCar::park(bool lot[], int size) {
	int spot = size;
	if (price() >= 50000) {
		for (int i = 0; i < size; i++) {
			if ()
		}
	} else {

		Automobile::park(lot, size);
	}
}

#endif

















