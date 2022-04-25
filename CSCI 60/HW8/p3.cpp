#include <iostream>

using namespace std;

void reverse(int a[], int first, int last) {
	if (first >= last) {
		return ;
	} else {
		int temp = a[first];
		a[first] = a[last];
		a[last] = temp;
		reverse(a, first+1, last-1);
	}
}

int main() {
	int a[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	reverse(a, 0, 4); 
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}