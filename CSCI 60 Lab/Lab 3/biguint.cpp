#include "biguint.h"
//1
biguint::biguint() {
	for (int i = 0; i < CAPACITY; i++) {
		data_[i] = 0;
	}
}

//2-3
biguint::biguint(const std::string & s) {
	for (size_t i = 0; i < CAPACITY-1; i++) {
		data_[i] = 0;
	}
	int j = 0;
	for (int i = s.size()-1; i >= 0; i--) {
		char c = s[i];
		data_[j] = c - '0';
		j++;
	}
}

//4
unsigned short biguint::operator [](std::size_t pos) const {
	if (pos > CAPACITY) {
		return 0;
	}
	return data_[pos];
}

//5
std::ostream& operator <<(std::ostream& out, const biguint& b) {
	for (size_t i = b.CAPACITY-1; i > 0; i--) {
		out << b[i-1];
	}
	return out;
}

//6-7
void biguint::operator += (const biguint & b) {
	for (size_t i = 0; i < CAPACITY; i++) {
		data_[i] += b[i];
		if (data_[i] > 9) {
			data_[i] -= 10;
			data_[i+1]++;
		}
	}
}

//Homework 3

//8
biguint operator + (const biguint & b1, const biguint & b2) {
	biguint bsum;
	bsum += b1;
	bsum += b2;
	return bsum;
}

//9
int biguint::compare(const biguint & b) const {
	for (size_t i = CAPACITY-1; i >= 0; i--) {
		if(data_[i] > b[i]) {
			return 1;
		} else if (data_[i] < b[i]) {
			return -1;
		}
	}
	return 0;
}

bool operator < (const biguint & b1, const biguint & b2) {
	if (b1.compare(b2) == -1) {
		return true;
	}
	return false;
}
bool operator <= (const biguint & b1, const biguint & b2) {
	if (b1.compare(b2) == -1 || b1.compare(b2) == 0) {
		return true;
	}
	return false;
}
bool operator != (const biguint & b1, const biguint & b2) {
	if (b1.compare(b2) == 1 || b1.compare(b2) == -1) {
		return true;
	}
	return false;
}
bool operator == (const biguint & b1, const biguint & b2) {
	if (b1.compare(b2) == 0) {
		return true;
	}
	return false;
}
bool operator >= (const biguint & b1, const biguint & b2) {
	if (b1.compare(b2) == 1 || b1.compare(b2) == 0) {
		return true;
	}
	return false;
}
bool operator > (const biguint & b1, const biguint & b2) {
	if (b1.compare(b2) == 1) {
		return true;
	}
	return false;
}


//10
void biguint::operator -= (const biguint & b) {
	for (size_t i = 0; i < CAPACITY; i++) {
		data_[i] -= b[i];
		if (data_[i] < 0) {
			data_[i] += 10;
			data_[i+1]--;
		}
	}
}

biguint operator - (const biguint & b1, const biguint & b2) {
	biguint bsub;
	bsub = b1;
	bsub -= b2;
	return bsub;
}

//11

std::string biguint::toString() {
	std::string result = "";
	char c = ' ';
	int j = CAPACITY-1;
	while (data_[j] == 0) {
		j--;
	}
	for (size_t i = j+1; i > 0; i--) {
		c = data_[i-1] + '0';
		result += c;
	}
	return result;
}




