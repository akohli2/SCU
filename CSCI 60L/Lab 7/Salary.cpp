#include <iostream>
 
using namespace std;


int salary(int n) {
	if (n == 0) {
		return 50;
	} else {
		return salary(n-1)*1.1+5;
	}
}

int main() {
	cout << salary(1) << endl;
	return 0;
}