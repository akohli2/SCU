#ifndef DSET_H
#define DSET_H
#include "duset.h"

class dSet: public dUSet {
public:
	dSet();
	dSet(const DynamicBag &b);
};