#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	ifstream in("input.txt");

	if(in.fail()) {
		cout << "open failed" << endl;
		exit(1);
	}

	while(!in.eof()) {
		string s;
		int pos = 0;
		map<string, vector<int> > m;
		while(in >> s) {
			m[s].push_back(pos++);
		}

		in.close();

		for (auto e:m) {
			cout << e.first << ": ";
			for (auto p: e.second) {
				cout << p << " ";
			}
			cout << endl;
		}

		return 0;
	}
}