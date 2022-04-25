#ifndef DUSET_H
#define DUSET_H

#include "dynamicbag.h"

using namespace std;

class dUSet: public DynamicBag {
public:
	dUSet();
	dUSet(DynamicBag b);
	void insert(int target);
private:
	
};

#endif