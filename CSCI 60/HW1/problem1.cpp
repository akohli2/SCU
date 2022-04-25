#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeletter (string names[], int size, char letter, ofstream& out) {
	cin >> names[size];
	if (names[size].at(0) == letter) {
		out << names[size];
	}
	size++;
}

int main() {
	ifstream in_stream;
	ofstream out_stream;

	in_stream.open("names.txt");
	out_stream.open("names1.txt");

	if (in_stream.fail() || out_stream.fail()) {
		cout << "Open failed" << endl;
		exit(1);
	}

	int filesize = 0;
	
	while (!in_stream.eof()) {
		string name = "";
		in_stream >> name;
		filesize++;
	}

	string names[filesize];

	while (!in_stream.eof()) {
		int i = 0;
		while (i != filesize) {
			in_stream >> names[i];
			i++;
		}
	}

	while (!in_stream.eof()) {
		char letter = 'a';
		while (letter <= 'z') {
			writeletter(names, filesize, letter, out_stream);
			letter++;
		}
	}

	in_stream.close();
	out_stream.close();

	return 0;
}