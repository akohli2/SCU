#ifndef P2_H
#define P2_H
#include <cmath>

template <typename T>
class tmplt{
private:
  T arr[10];
  int dimension;
public:
	tmplt();
	tmplt(int dim);
	tmplt(int dim, T a[]);
	int dimension_() { return dimension;}
	T index(int i) { return arr[i];}

	void operator =(tmplt<T> d) {
		dimension = d.dimension_();
		for (int i = 0; i < dimension; i++) {
			arr[i] = d.index(i);
		}
	}

	void operator +=(tmplt<T> d) {
		if (dimension < d.dimension_()) {
			dimension = d.dimension_();
		}
		for (int i = 0; i < dimension; i++) {
			arr[i] = arr[i] + d.index(i);
		}
	}
};


template <typename T>
tmplt<T>::tmplt() {
	dimension = 0;
}


template <typename T>
tmplt<T>::tmplt(int dim) {
	dimension = dim;
	for(int i = 0; i < 10; i++) {
		arr[i] = T();
	}
}


template <typename T>
tmplt<T>::tmplt(int dim, T a[]) {
	dimension = dim;
	for(int i = 0; i < dim; i++) {
		arr[i] = a[i];
	}
}

template <typename T>
tmplt<T> operator +(tmplt<T> &d1, tmplt<T> &d2) {
	int dim = d1.dimension_() + d2.dimension_();
	T a[10];
	tmplt<T> d3(dim, a);
	for (int i = 0; i < 10; i++) {
		d3.index(i) += d1.index(i);
		d3.index(i) += d2.index(i);
	}
	return d3;
}

template <typename T>
bool operator ==(tmplt<T> &d1, tmplt<T> &d2) {
	if (d1.dimension_() == d2.dimension_()) {
		for (int i = 0; i < 10; i++) {
			if (d1.index(i) == d2.index(i)) {

			} else {
				return false;
			}
		}
	} else {
		return false;
	}
	return true;
}

template <typename T>
int operator -(std::string &s1, std::string &s2) {
	return s1[0]-s2[0];
}

template <typename T>
float distance(tmplt<T> &d1, tmplt<T> &d2) {
	float sum = 0;
	for (int i = 0; i < d1.dimension_(); i++) {
		sum += (d1.index(i)-d2.index(i))*(d1.index(i)-d2.index(i));
	}
	return sqrt(sum);
}


#endif
