#include <iostream>

using namespace std;

template <typename T1, typename T2>
//T1 needs to support [], ==
//T2 needs to support <, ++

T1 frequent(T1 a[], T2 size) {
	T1 mode = a[0];
	int maxCount = 0;
	for (T2 i = 0; i < size; i++) {
		int count = 0;
		for (T2 j = 0; j < size; j++) {
			if(i != j && a[i] == a[j]) {
				count++;
			}
		}
		if (count > maxCount) {
			maxCount = count;
			mode = a[i];
		}
	}
	return mode;
}

int main() {
	int arr[] = {6, 2, 3, 2, 6, 2};
	cout << frequent(arr, 6) << endl;
	return 0;
}

