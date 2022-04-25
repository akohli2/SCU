#include <iostream>

using namespace std;

void reserve(node * & head, node * & tail, std::size_t num) {
	for (int i = 0; i < num; i++) {
		if (head == nullptr) {
			head = new node(0, nullptr);
		} else {
			tail->set_link(new node(0, nullptr));
			tail = tail->link();
		}
	}
}