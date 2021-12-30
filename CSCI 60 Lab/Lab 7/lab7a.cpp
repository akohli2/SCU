#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int main() {
	ifstream in;
	ofstream out;

	in.open("names.rtf");
	out.open("set.txt");

	if (in.fail() || out.fail()) {
		exit(1);
	}

	set<string> s1;
	string s;
	while (!in.eof()) {
		getline(in, s);
		s1.insert(s);
	}

	// for (auto e:s1) {
	// 	out << e << endl;
	// }

	int count = 0;
	for (auto e:s1) {
		cout << e << endl;
		count++;
	}

	cout << count << endl; //111

	in.close();
	out.close();
}