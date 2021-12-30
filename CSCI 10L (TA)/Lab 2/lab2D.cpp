#include <iostream>
#include <string>
using namespace std;

int main() {
	string p1, p2;
	cout << "Enter parent 1's gentotype: " << endl;
	cin >> p1;
	cout << "Enter parent 2's gentotype: " << endl;
	cin >> p2;

	if (p1 == "GG" && p2 == "GG") {
		cout << "GG: 100%" << endl;
	} else if ((p1 == "GG" && p2 == "Gg") || (p1 == "Gg" && p2 == "GG")) {
		cout << "GG: 50%" << endl;
		cout << "Gg: 50%" << endl;
	} else if ((p1 == "GG" && p2 == "gg") || (p1 == "gg" && p2 == "GG")) {
		cout << "Gg: 100%" << endl;
	} else if (p1 == "Gg" && p2 == "Gg") {
		cout << "GG: 25%" << endl;
		cout << "Gg: 50%" << endl;
		cout << "gg: 25%" << endl;
	} else if ((p1 == "Gg" && p2 == "gg") || (p1 == "gg" && p2 == "Gg")) {
		cout << "Gg: 50%" << endl;
		cout << "gg: 50%" << endl;
	} else if (p1 == "gg" && p2 == "gg") {
		cout << "gg: 100%" << endl;
	}
	return 0;
}
