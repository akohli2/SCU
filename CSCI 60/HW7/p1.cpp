#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream in;
	ofstream out;

	in.open("sample1.txt");
	out.open("p1.txt");

	if (in.fail() || out.fail()) {
		exit(1);
	}

	// a

	vector<string> v;
	string s;
	while (!in.eof()) {
		in >> s;
		v.push_back(s);
	}

	for (auto e:v) {
		sort(v.begin(), v.end());
	}

	for (auto e:v) {
		out << e << endl;
	}

	//b

	vector<string> v;
	string s;
	while (!in.eof()) {
		in >> s;
		v.push_back(s);
	}

	for (auto e:v) {
		sort(v.begin(), v.end());
	}

	vector<string>::iterator i;
	vector<string>::iterator j; 
	for (i = v.begin(); i < v.end(); i++) {
		for (j = v.begin()+1; j < v.end(); j++) {
			if ((*i) == (*j)) {
				v.erase(j);
			}
		}
	}
	int count = 1;
	string word = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (word != v[i]) {
			out << word << " " << count << endl;
			count = 0;
			word = v[i];
		}
		count++;
	}

	out << word << " " << count << endl;

	in.close();
	out.close();
}