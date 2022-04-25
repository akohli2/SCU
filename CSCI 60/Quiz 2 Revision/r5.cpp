#include <iostream>

using namespace std;

int EvenSum(int n) {
	if (n==0) {
		return 0;
	} else {
		return (EvenSum(n-1)+2*n);
	}
}

int main() {
	cout << EvenSum(3) << endl;
}