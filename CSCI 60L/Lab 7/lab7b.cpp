#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main() {
	ifstream in;
	ofstream out;

	in.open("names.rtf");
	out.open("map.txt");

	if (in.fail() || out.fail()) {
		exit(1);
	}

	map<string,int> m2;
	string s;
	while (!in.eof()) {
		getline(in, s);
		m2[s]++;
	}

	// for (auto e:m2) {
	// 	out << e.first << " " << e.second << endl;
	// }

	double sum = 0;
	double count = 0;
	for (auto e:m2) {
		sum += e.second;
		count++;
	}
	cout << sum << endl; //148
	cout << count << endl;
	double avg = sum/count;
	cout << avg << endl;

	in.close();
	out.close();
}