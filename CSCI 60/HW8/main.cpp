#include "node.h"

#include <iostream>

using namespace std;

int main(){
    node *head = new node(4, nullptr);
    node *tail(head);

    head = new node(8, head);
    head = new node(1, head);
    head = new node(5, head);
    head = new node(1, head);
    head = new node(3, head);

    cout << head << endl;

    list_reverse(head, tail);
    cout << head << endl;

    list_clear(head, tail);
    cout << head << endl;

    return 0;
}