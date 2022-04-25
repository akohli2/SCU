#include <iostream>
#include <string>

using namespace std;

struct Date {
	int month;
	int day;
	int year;
};

// struct Student {
// 	double gpa;
// 	int id;
// 	string firstname;
// 	string lastname;
// 	Date bd;
// };

class Student {
public:
	double get_gpa() {
		return gpa;
	}
	double get_id() {
		return id;
	}
	string get_firstname() {
		return firstname;
	}
	string get_lastname() {
		return lastname;
	}
	Date get_bd() {
		return bd;
	}
	Student() {
		gpa_ = 0;
		id_ = 0;
		firstname_ = "";
		lastname_ = "";
		Date d = {0, 0, 0};
		bd_ = d;
	}
	Student(double g, int i, string first, string last, Date b) {
		gpa = g;
		id = i;
		firstname = first;
		lastname = last;
		bd = b;
	}

private:
	double gpa_;
	int id_;
	string firstname_;
	strinbg lastname_;
	Date bd_;
};

int main() {
	Date d;
	d.month = 3;
	d.day = 5;
	d.year = 1998;

	Student bob = Student(3.2, 1992371, "Bob", "Bobberson", d);

	Student sophomores[1] = {bob};

	for (int i = 0; i < 1; i++) {
		cout << sophomores[i].firstname_ << firstname() << endl;
	}


}


