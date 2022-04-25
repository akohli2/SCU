#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Animal {
	string name;
	char gender;
	int age;
	float price;
	string type;
};

Animal Cheapest(string type, Animal a[], int size) {
	int expensiveAnimal = 0;
	int cheapestAnimal = 0;
	for (int i = 0; i < size; i++) {
		while (a[i].type == type) {
			if (a[i].price > expensiveAnimal) {
				expensiveAnimal = i;
			}
		}
		int cheapestAnimal = expensiveAnimal;
		for (int i = 0; i < size; i++) {
			if (a[i].price < a[cheapestAnimal].price) {
				cheapestAnimal = i;
			}
		}
	}

	return a[cheapestAnimal];
}

bool livetogether(Animal a, Animal b) {
	if (a.type == b.type) {
		return true;
	}
	return false;
}

int main() {
	Animal a;
	a.name = "Jack";
	a.gender = 'M';
	a.age = 10;
	a.price = 100.00;
	a.type = "dog";

	Animal b;
	b.name = "Lucy";
	b.gender = 'F';
	b.age = 14;
	b.price = 150.00;
	b.type = "dog";

	bool test = livetogether(a, b)

	cout << test << endl;

	Animal arr[] = {a, b};

	Animal cheapest = Cheapest("dog", arr, 2);

	cout << cheapest.name << endl;

}
