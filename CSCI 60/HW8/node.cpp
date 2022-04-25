#include "node.h"

node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}

int node::data() const
{
    return data_;
}

node * node::link()
{
    return link_;
}

//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function doesn't change anything - On a const node*, you can only call const functions
{
    return link_;
}

void node::set_data(const int & newdata)
{
    data_ = newdata;
}

void node::set_link(node * newlink)
{
    link_ = newlink;
}

//////////////////////////////////////////////////////////////////

void list_clear(node * &head_ptr, node * &tail_ptr) {
    node *p = head_ptr;
    while(p != nullptr) {
        head_ptr = p->link();
        delete p;
        p = head_ptr;
    }
}

void list_reverse(node * &head_ptr, node * &tail_ptr) {    
    node *p = nullptr;
    node *c = head_ptr;
    node *n = nullptr;

    while (c!=nullptr) {
        n = c->link();
        c->set_link(p);
        p = c;
        c = n;
    }
    head_ptr = p;  
}

//I overloaded this so I could output my linked list when testing my functions in main
std::ostream & operator <<(std::ostream & os, const node * head){
    for(const node *p = head; p!= nullptr; p=p->link()){
        os << p->data() << " ";
    }
    return os;
}








