 #include <iostream>

using namespace std;

void insert_at(node * & head, node::value_type value, std::size_t pos) {
	std::size_t count = 0;
	for (node* p = head; count < pos-1 && p != nullptr; p=p->head) {
		if (p!=nullptr) {
			p->setlink(new node(value, p->link()));
		}
	}
}