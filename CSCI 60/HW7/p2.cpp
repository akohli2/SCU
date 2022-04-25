#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int main() {
	ifstream in;
	ofstream out;

	in.open("sample1.txt");
	out.open("p2.txt");

	if (in.fail() || out.fail()) {
		exit(1);
	}

	set<string> s;
	string temp;
	while (!in.eof()) {
		in >> temp;
		s.insert(temp);
	}

	for (auto e:s) {
		out << e << endl;
	}

	in.close();
	out.close();
}

//I prefer vector as it still keeps the multiples while also keeping them sorted. It's great that it's sorted because then it will take less time to find an element in the vector. Keeping multiples is also good in case you want to count how many times an element occurs in a container. A set cannot do these things, therefore, a vector is better. One other bonus is that the [] operator works so you can loop over vectors without having to use an auto loop or an interator.
