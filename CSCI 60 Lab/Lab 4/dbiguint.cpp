#include "dbiguint.h"

//1
dbiguint::dbiguint() {
	data_ = new unsigned short [1];
	data_[1] = 0;
	capacity_ = 1;
}

dbiguint::dbiguint(const std::string & s) {
	capacity_ = s.size();
	data_ = new unsigned short [capacity_];
	int j = capacity_-1;
	for (size_t i = 0; i < capacity_; ++i) {
		data_[i] = s[j] - '0';
		j--;
	}
}

//2
std::size_t dbiguint::size() const{
	return capacity_;
}

unsigned short dbiguint::operator [](std::size_t pos) const {
	if (pos > capacity_) {
		return 0;
	}
	return data_[pos];
}

std::ostream & operator << (std::ostream & out, const dbiguint & b) {
	for (std::size_t i = b.size(); i > 0; i--) {
		out << b[i-1];
	}
	return out;
}

//3
void dbiguint::reserve(std::size_t newcapacity_) {
	if (newcapacity_ > capacity_) {
		unsigned short *temp_ = new unsigned short [newcapacity_];
		for (std::size_t i = 0; i < capacity_; ++i) {
			temp_[i] = data_[i];
		}
		for (std::size_t i = capacity_; i < newcapacity_; ++i) {
			temp_[i] = 0;
		}
		delete [] data_;
		data_ = temp_;
		temp_ = nullptr;
		capacity_ = newcapacity_;
	}
}

//4 

void dbiguint::operator +=(const dbiguint & b) {
	if (capacity_ < b.size()) {
		reserve(b.size());
	}
	for (size_t i = 0; i < size(); ++i) {
		data_[i] += b[i];
		if (data_[i] > 9) {
			data_[i] -= 10;
			data_[i+1]++;
			if (i == capacity_-1) {
				reserve(capacity_);
			} 
		}
	}
}

//5

dbiguint::~dbiguint() {
	delete [] data_;
	data_ = nullptr;
	capacity_ = 0;
}

//HOMEWORK 4

//6

int dbiguint::compare(const dbiguint & b) const {
	for (size_t i = capacity_-1; i >= 0; i--) {
		if(data_[i] > b[i]) {
			return 1;
		} else if (data_[i] < b[i]) {
			return -1;
		}
	}
	return 0;
}

dbiguint operator +(const dbiguint & b1, const dbiguint & b2) {
	dbiguint bsum;
	bsum += b1;
	bsum += b2;
	return bsum;
}








bool operator < (const dbiguint & b1, const dbiguint & b2) {
	if (b1.compare(b2) == -1) {
		return true;
	}
	return false;
}
bool operator <= (const dbiguint & b1, const dbiguint & b2) {
	if (b1.compare(b2) == -1 || b1.compare(b2) == 0) {
		return true;
	}
	return false;
}
bool operator != (const dbiguint & b1, const dbiguint & b2) {
	if (b1.compare(b2) == 1 || b1.compare(b2) == -1) {
		return true;
	}
	return false;
}
bool operator == (const dbiguint & b1, const dbiguint & b2) {
	if (b1.compare(b2) == 0) {
		return true;
	}
	return false;
}
bool operator >= (const dbiguint & b1, const dbiguint & b2) {
	if (b1.compare(b2) == 1 || b1.compare(b2) == 0) {
		return true;
	}
	return false;
}
bool operator > (const dbiguint & b1, const dbiguint & b2) {
	if (b1.compare(b2) == 1) {
		return true;
	}
	return false;
}






