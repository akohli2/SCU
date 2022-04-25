#include <iostream>

using namespace std;

int sequence(int n) {
	if (n == 0 || n == 1) {
		return 1;
	} else {
		return sequence(n-2)+n-1;
	}
}

int main() {
	cout << sequence(7) << endl;
}