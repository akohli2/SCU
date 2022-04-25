#include <iostream>

using namespace std;

template <typename T>

// > and - operators must be supported
T abs(T a, T b) {
	if ((a-b) > (b-a)) {
		return a-b;
	} else {
		return b-a;
	}
}

int main() {
	int a = 3;
	int b = 2;
	cout << abs(a, b) << endl;
}