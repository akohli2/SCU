#include <iostream>

using namespace std;

struct Time {
	int hour;
	int minute;
};

class Carpool {
public:
	string names[5];
	int passengers;
	Time arrival;

	void print () {
		for (int i = 0; i < passengers; i++) {
			cout << names[i] << " " << endl;
		}
	}

};


Time earlier (Time t1, Time t2) {
	return t1;
};

Carpool combineCarpool (Carpool car1, Carpool car2) {

	if (car1.passengers + car2.passengers <=5) {
		
		Carpool car3;

		car3.passengers = car1.passengers + car2.passengers;

		for (int i = 0; i < car1.passengers; i++) {
			car3.names[i] = car1.names[i];
		}

		int j = 0;

		for (int i = car1.passengers; i < car3.passengers; i++) {
			car3.names[i] = car2.names[j];
			j++;
		}

		car3.arrival = earlier(car1.arrival, car2.arrival);

		return car3;

	} else {
		Carpool nullcar;
		nullcar.passengers = 0;
		return nullcar;
	}

	
};

int main() {
	Carpool car1;

	car1.names[0] = "Bill";
	car1.names[1] = "Billy";
	car1.names[2] = "Bob";
	car1.passengers = 3;
	car1.arrival.hour = 3;
	car1.arrival.minute = 30;

	car1.print();

}

