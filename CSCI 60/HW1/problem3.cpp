#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Movie {
private:
	string name;
	string rating;
	double earnings;


	string get_name() {
		return name;
	}
	string get_rating() {
		return rating;
	}
	double get_earnings() {
		return earnings;
	}

	string set_name(string n) {
		name = n;
		return name;
	} 
	string set_rating(string r) {
		rating = r;
		return rating;
	}
	double set_earnings(double e) {
		earnings = e;
		return earnings;
	}


public:

	Movie();
	Movie(string name_, string rating_, double earnings_);

	double movieShowing(int n) {
		earnings = 12.00 * n;
		return earnings;
	}

	Movie mergeMovie(Movie m) {
		Movie combined;
		if (m.get_name() == name) {
			combined.get_name() = name;
			if (m.get_rating() == "R" || rating == "R") {
				combined.rating = "R";
			}
			else if (m.get_rating() == "PG-13" || rating == "PG-13") {
				combined.rating = "PG-13";
			}
			else if (m.get_rating() == "PG" || rating == "PG") {
				combined.rating = "PG";
			}
			else if (m.get_rating() == "G" || rating == "G") {
				combined.rating = "G";
			}

			combined.earnings = m.get_earnings() + earnings;

		} else {
			combined.name = "Could not combine";
		}
		return combined;
	}
};

Movie::Movie() {
	name = "";
	rating = "";
	earnings = 0;
}
Movie::Movie(string name_, string rating_, double earnings_) {
	name = name_;
	rating = rating_;
	earnings = earnings_;
} 

int main() {
	Movie mov("Star Wars", "PG", 1234);
	cout << mov.get_name() << endl;
	cout << mov.get_rating() << endl;
	cout << mov.get_earnings() << endl;

	cout << Movie movieShowing(50) << endl;

	Movie mov2("Star Wars", "R", 5678);

	Movie mov3 = movie.mergeMovie(m2);
	cout << mov3.get_name() << endl;
	cout << mov3.get_rating() << endl;
	cout << mov3.get_earnings() << endl;
}
