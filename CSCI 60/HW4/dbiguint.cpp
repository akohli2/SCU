#include "dbiguint.h"
#include <math.h>

//1
dbiguint::dbiguint() {
	data_ = new unsigned short [1];
	data_[0] = 0;
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
	unsigned short i = 0;
	if (pos >= 0 && pos < capacity_) {
		i = data_[pos];
	}
	return i;
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
	} else if (newcapacity_ < capacity_) {
		unsigned short *temp_ = new unsigned short [newcapacity_];
		for (std::size_t i = 0; i < newcapacity_; ++i) {
			temp_[i] = data_[i];
		}
		// for (std::size_t i = capacity_; i < newcapacity_; ++i) {
		// 	temp_[i] = 0;
		// }
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
	for (size_t i = 0; i < capacity_; ++i) {
		if (data_[i] > 9) {
			if (i == capacity_-1) {
				reserve(capacity_+1);
			} 	
			data_[i] -= 10;
			data_[i+1]++;
		} else {
			data_[i] = data_[i] + b[i];
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

//Problem 2

dbiguint::dbiguint(const dbiguint & b) {
	if (capacity_ < b.size()) {
		reserve(b.size());
	} else {
		capacity_ = b.size();
	}
	data_ = new unsigned short [capacity_];
	for (size_t i = 0; i < capacity_; ++i) {
		data_[i] = b[i];
	}
}


//6

int dbiguint::compare(const dbiguint & b) const {
	if (capacity_ > b.size()) {
		return 1;
	} else if (capacity_ < b.size()) {
		return -1;
	} else if (capacity_ == b.size()) {
		for (size_t i = capacity_-1; i > -1; --i) {
			if (data_[i] > b[i]) {
				return 1;
			} else if (data_[i] < b[i]) {
				return -1;
			} else if (data_[i] < b[i]) {

			}
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


//7

void dbiguint::operator =(const dbiguint & b) {
	if (this == &b) {
		return;
	} else {
		capacity_ = b.size();
		reserve(capacity_);
		delete [] data_;
		data_ = new unsigned short [capacity_];
		for (unsigned short i = 0; i < capacity_; ++i) {
			data_[i] = b[i];
		}
	}
}

// //10

std::istream & operator >> (std::istream & in, dbiguint & b) {
	std::cout << "Enter number: " << std::endl;
	std::string input;
	in >> input;
	dbiguint b1(input);
	b = b1;
	return in;
}

// //Problem 3

// //8

void dbiguint::operator -=(const dbiguint & b) {
	int temp = 0;
  	for (size_t i = 0; i < b.size(); ++i) {
	  	temp = data_[i] - b.data_[i];
	  	if(temp < 0) {
		    if(i == (capacity_ - 1)) {
				reserve((capacity_ -1));
			    int j = i+1;
			    while(data_[j] == 0) {
				    if (data_[j] == 0) {
					    reserve((capacity_ -1));
    				}
    				--j;
    			}
    		}
    		data_[i] = data_[i] + 10;
    		data_[i] = data_[i] - b.data_[i];
    		data_[i+1] = data_[i+1] - 1;
  		} else {
    		data_[i]=temp;
  		}
  		if ((i == capacity_-1) && (data_[i] == 0)) {
    		reserve(capacity_-1);
  		}
	}
	int j = capacity_;
	int count = 0;
	while (data_[j] == 0) {
		count++;
		j--;
	}
	reserve(capacity_-count);
}

dbiguint operator -(const dbiguint & b1, const dbiguint & b2) {
	dbiguint bsub;
	bsub = b1;
	bsub -= b2;
	return bsub;
}

std::string dbiguint::toString() {
	std::string result = "";
	char c = ' ';
	int j = capacity_-1;
	while (data_[j] == 0) {
		j--;
	}
	for (size_t i = j+1; i > 0; i--) {
		c = data_[i-1] + '0';
		result += c;
	}
	return result;
}

//9

void dbiguint::operator *=(const dbiguint & b) {
	int m;
	dbiguint temp;
	dbiguint temp2;
	int counter;
	temp.reserve(19);
	for (size_t i = 0; i < capacity_; ++i) {
		for (size_t j = 0; j < temp.size(); ++j) {
			temp.data_[j] = 0;
		}
		for (size_t k = 0; k < b.size(); ++k) {
			m = (data_[i] * b.data_[k]);
			temp.data_[i+k] += (m % 10);
			temp.data_[i+k+1] += (m / 10);
		}
		temp2 += temp;
	}
	counter = 0;

	for (size_t l = temp2.capacity_-1; l > -1; --l) {
		if (temp2.data_[l] == 0) {
			counter++;
		} else {
			break;
		}
	}
	temp2.reserve(temp2.size()-counter);
	*this = temp2;
}

dbiguint operator *(const dbiguint &b1, const dbiguint &b2) {
	int m;
	int temp[20];
	dbiguint temp2;
	int counter;
	temp2.reserve(19);
	std::string s = "";
	for (size_t i = 0; i < b1.size(); ++i) {
		for (size_t j = 0; j < 19; ++j) {
			temp[j] = 0;
		}
		for (size_t k = 0; k < b2.size(); ++k) {
			m = (b1[i] * b2[k]);
			temp[i+k] += (m % 10);
			temp[i+k+1] += (m / 10);
		}
		s = toString(temp);
		dbiguint temp3(s);
		temp2 += temp3;
	}
	counter = 0;
	for (size_t l = temp2.size()-1; l > -1; --l) {
		if (temp[l] == 0) {
			counter += 1;
		} else {
			break;
		}
	}
	temp2.reserve(temp2.size()-counter);
	return temp2;
}













