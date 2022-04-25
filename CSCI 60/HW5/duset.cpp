#include "dynamicbag.h"
#include "duset.h"

dUSet::dUSet(): DynamicBag() {

}

dUSet::dUSet(DynamicBag b): DynamicBag(b) {
	DynamicBag temp(b);
	for (size_t i = 0; i < temp.size(); ++i) {
		for (size_t j = 0; j < temp.size(); ++j) {
			if (i != j) {
				if (temp[i] == temp[j]) {
					temp.erase_one(b[j]);
				}
			}
		}
	}
	*this = temp;
}



void dUSet::insert(int target) {
	DynamicBag temp(*this);
	bool replica = false;
	for (size_t i = 0; i < temp.size(); ++i) {
		if (temp[i] == target) {
			replica = true;
		}
	}
	if (replica == false) {
		temp.insert(target);
	}
	*this = temp;
}

