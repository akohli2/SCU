#ifndef NODE_H
#define NODE_H
#include <iostream>
class node
{
public:


    // pre: none
    // post: creates a new node with given data and link values
    node(const int & initdata, node * initlink);

    // pre: none
    // post: creates a new node with defaults: data=0 and link=nullptr
    node();

    // pre: none
    // post: returns data value stored in this node
    int data() const;

    // pre: none
    // post: returns link value stored in this node
    node * link();

    // pre: none
    // post: returns CONSTANT link value stored in this node
    const node * link() const;

    // pre: none
    // post: sets the data field to given value
    void set_data(const int & newdata);

    // pre: none
    // post: sets the link field to given value
    void set_link(node * newlink);


private:
    int data_;
    node * link_;
    // invariants:
    //  data_ holds the data value stored in this node
    //  link_ holds the address of the next node
};

void list_reverse(node * &head_ptr, node * &tail_ptr);
void list_clear(node * &head_ptr, node * &tail_ptr);

//I overloaded this so I could output my linked list when testing my functions in main
std::ostream & operator <<(std::ostream & os, const node * head);



#endif // NODE_H