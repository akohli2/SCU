#include "duset.h"
#include "dset.h"

dSet::dSet(): dUSet() {

}

dSet::dSet(DynamicBag b): dUSet() {
	DynamicBag temp;
	int min = b[0];
	size_t j = 0;
	for (size_t i = 0; i < b.size(); ++i) {
		if (b[i] < max) {
			min = b[i];
			temp[j] = min;
			b.erase_one(min);
			++j;
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
		if (temp[i-1] < target && temp[i+1] > target) {
			temp.insertAt(target, i);
		}
	}
	*this = temp;
}