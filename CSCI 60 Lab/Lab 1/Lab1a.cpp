#include <iostream>

using namespace std;

struct Time {
	int hour;
	int minute;
};

struct Carpool {
	string names[5];
	int passengers;
	Time arrival;
};


Time earlier (Time t1, Time t2) {
	return t1;
};

Carpool combineCarpool (Carpool car1, Carpool car2) {

	Carpool car3;

	if (car1.passengers + car2.passengers <=5) {
		

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

	} else {
		Carpool null;
		null.passengers = 0;
		return null;
	}

	return car3;
};

int main() {
	Carpool car1;
	Carpool car2;
	car1.names[0] = "Bill";
	car1.names[1] = "Billy";
	car1.names[2] = "Bob";
	car1.passengers = 3;
	car1.arrival.hour = 3;
	car1.arrival.minute = 30;

	car2.names[0] = "Nancy";
	car2.names[1] = "Tina";
	car2.passengers = 2;
	car2.arrival.hour = 2;
	car2.arrival.minute = 15;

	Carpool car3 = combineCarpool(car1, car2);
	for (int i = 0; i < car3.passengers; i++) {
		cout << car3.names[i] << " " << endl;
	}
	cout << "Passengers: " << car3.passengers << endl;
	cout << "Arrival time: " << car3.arrival.hour << ":" << car3.arrival.minute << endl;

}
