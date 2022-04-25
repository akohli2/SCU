#include <iostream>

using namespace std;

class SDcard {
private:
	string name;
	int capacity;
	int usedMem;
	const int PICSIZE = 50;
public:
	SDcard();
	SDcard(string n, int c, int m);
	string get_name() {return name;}
	int get_capacity() {return capacity;}
	int get_usedMem() {return usedMem;}
	bool takepicture();
	void empty();
	bool dump(SDcard& sdc);
};

SDcard::SDcard() {
	name = "";
	capacity = 0;
	usedMem = 0;
}

SDcard::SDcard(string n, int c, int m) {
	name = n;
	capacity = c;
	usedMem = m;
}

bool SDcard::takepicture() {
	if (capacity > usedMem + PICSIZE) {
		usedMem = usedMem + PICSIZE;
		return true;
	} else {
		return false;
	}
}

void SDcard::empty() {
	usedMem = 0;
}

bool SDcard::dump(SDcard& sdc) {
	if (capacity > usedMem + sdc.usedMem) {
		usedMem = usedMem + sdc.usedMem;
		sdc.usedMem = 0;
		return true;
	} else {
		return false;
	}
}

int main() {
	SDcard s1("one", 400, 50);
	SDcard s2("two", 500, 100);
	cout << s1.get_usedMem() << endl;
	s1.takepicture();
	cout << s1.get_usedMem() << endl;
	s2.dump(s1);

	cout << s1.get_usedMem() << endl;
	cout << s2.get_usedMem() << endl;

	s2.empty();
	cout << s2.get_usedMem() << endl;

	return 0;
}
