#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
	ifstream in;
	in.open("input.txt");

	if(in.fail()) {
		cout << "Open failed" << endl;
		exit(1);
	}

	vector<int> v1;
	int n;
	while(in >> n) {
		v1.push_back(n);
	}
	in.close();
	for (auto e:v1) {
		cout << e << endl;
	}
	sort(v.begin(), v.end());
	for (auto e:v1) {
		cout << e << endl;
	}
	return 0;
}