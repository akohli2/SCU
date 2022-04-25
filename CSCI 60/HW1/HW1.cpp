#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Problem 1

void writeletter (string names[], int size, char letter, ofstream& out) {
	for (int i = 0; i < size; i++) {
		string s = names[i];
		if (s[0] == letter) {
			out << names[i];
		}
	}
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

	string names[100];
	int filesize = 0;

	while (!in_stream.eof()) {
		in_stream >> names[filesize];
		filesize++;
	}

	while (!in_stream.eof()) {
		char letter = 'A';
		while (letter <= 'Z') {
			writeletter(names, filesize, letter, out_stream);
			letter++;
		}
	}

	in_stream.close();
	out_stream.close();

	return 0;
}

// //Problem 2

// struct Animal {
// 	string name;
// 	char gender;
// 	int age;
// 	float price;
// 	string type;
// };

// Animal Cheapest(string type, Animal a[], int size) {
// 	int expensiveAnimal = 0;
// 	for (int i = 0; i < size; i++) {
// 		while (a[i].type == type) {
// 			if (a[i].price > expensiveAnimal) {
// 				expensiveAnimal = i;
// 			}
// 		}
// 		int cheapestAnimal = expensiveAnimal;
// 		for (int i = 0; i < size; i++) {
// 			if (a[i].price < a[cheapestAnimal].price) {
// 				cheapestAnimal = i;
// 			}
// 		}
// 	}

// 	return a[cheapestAnimal];
// }

// bool livetogether(Animal a, animal b) {
// 	if (a.type == b.type) {
// 		return true;
// 	}
// 	return false;
// }

// Problem 3

// class Movie {
// 	string name;
// 	string rating;
// 	double earnings;

// 	double movieShowing(int n) {
// 		earnings = 12.00 * n;
// 		return earnings;
// 	}

// 	Movie mergeMovie(Movie m) {
// 		Movie Combined;
// 		if (m.name == name) {
// 			if (m.rating == "R" || rating == "R") {
// 				Combined.rating = "R";
// 			}
// 			else if (m.rating == "PG-13" || rating == "PG-13") {
// 				Combined.rating = "PG-13";
// 			}
// 			else if (m.rating == "PG" || rating == "PG") {
// 				Combined.rating = "PG";
// 			}
// 			else {
// 				Combined.rating = "G";
// 			}

// 			Combined.earnings = m.earnings + earnings;

// 		} 

// 		if (m.name != name) {
// 			Movie NCombined;
// 			NCombined.name == "Could not combine";
// 			return NCombined;
// 		}

// 		return Combined;
// 	}
// };





