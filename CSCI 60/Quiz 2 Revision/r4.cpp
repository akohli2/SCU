#include <iostream>

using namespace std;

template <class T>
T F(T arr[], T val, int size) {
	T smallest_dif;
	int num = 0;
	if (arr[0] >= val) {
		smallest_dif = arr[0] - val;
	} else {
		smallest_dif = val - arr[0];
	}
	for (int i = 1; i < size; i++) {
		if (arr[i] > val) {
			if (arr[i] - val < smallest_dif) {
				smallest_dif = arr[i] - val;
				num = arr[i];
			} 
		} else {
			if (val - arr[i] < smallest_dif) {
				smallest_dif = val - arr[i];
				num = arr[i];
			}
		}
	}
	return num;
}

int main() {
	int a[] = {1, 3, 4, 5, 8};
	cout << F(a, 6, 5) << endl;
}