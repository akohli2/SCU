#include <iostream>

using namespace std;

int ncounter(int a[], int size, int n) {
	if (size == 0) {
		return 0;
	} else {
		if (a[size-1] == n) {
			return (1+ncounter(a, size-1, n));
		} else {
			return (0+ncounter(a, size-1, n));
		}
	}
}

int main() {
	int a[] = {1, 2, 3, 4, 4};
	cout << ncounter(a, 5, 4) << endl;
	cout << ncounter(a, 5, 3) << endl;
}