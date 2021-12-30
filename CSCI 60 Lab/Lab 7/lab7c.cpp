#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	ifstream in;
	ofstream out;

	in.open("names.rtf");
	out.open("vector.txt");

	if (in.fail() || out.fail()) {
		exit(1);
	}

	vector<string> v3;
	string s;
	while (!in.eof()) {
		getline(in, s);
		v3.push_back(s);
	}

	for (auto e:v3) {
		out << e << endl;
	}

	in.close();
	out.close();
}