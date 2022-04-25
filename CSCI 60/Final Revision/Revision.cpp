
#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <vector>

void multiply(node<int> * &head, node<int> * &tail, int d) {
	for(node<int> * p = head; p != nullptr; p=p->link()) {
		new node(p->data()*d, p->link());
		delete p;
	}
}

/////

template <class T>
node<T> * unique_copy(const node<T> * head) {
	node<T> * newhead = new node(head->data(), nullptr);

}

//////

template<typename T>
int binarySearch(int first, int last, T arr[], T value) {
	int i = 0;
	if(i > last) {
		return -1;
	} else {
		if (a[i] == value) {
			return i;
		} else {
			i++;
		}
	}
}

//////

stuct Carpool {
	set<string> names;
	int month;
	int day;
};

int main() {
	ifstream in("file.txt");
	if (in.fail()) {
		cout << "Open failed" << endl;
		exit(1);
	}

	vector<Carpool> v;

	while (!in.eof()) {
		in >> 
	}
}































