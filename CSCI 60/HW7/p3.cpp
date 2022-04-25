#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
	ifstream in;

	in.open("sample2.txt");

	if (in.fail()) {
		cout << "open failed" << endl;
		exit(1);
	}

	map<int, pair<int, vector<string> > > m;

	int score;
	string name;
	while (!in.eof()) {
		in >> score;
		getline(in, name);
		for (int i = 0; i <= 10; i++) {
			if (score == i) {
				m[i].first++;
				m[i].second.push_back(name);
			}
		}
	}

	for (int i = 0; i <= 10; i++) {
		cout << i;
		for (int j = 1; j <= m[i].first; j++) {
			cout << "x";
		}
		cout << endl;
	}	

	int input;
	cout << "Input score to see names who achieved it: " << endl;
	cin >> input;
	for (auto e:m[input].second) {
		cout << e << ", ";
	}
	cout << endl;

	return 0;
}