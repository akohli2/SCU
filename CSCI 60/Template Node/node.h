
#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <ostream>
#include <iostream>

template <class T>
class node
{
public:
    typedef T value_type;
    node(const value_type & initdata_ = value_type(),//Calls the default constructor for the template type
        node * initlink_ = nullptr){
        data_ = initdata_;
        link_ = initlink_;
    }
    value_type data() const{
        return data_;
    }
    value_type & data(){
        return data_;
    }
    node * link(){
        return link_;
    }
    const node * link() const{
        return link_;
    }
    void setdata(const value_type & newdata){
        data_ = newdata;
    }
    void setlink(node * newlink){
        link_ = newlink;
    }
private:
    value_type data_;
    node * link_;
};

// linked list toolkit functions
template <class T>
std::size_t list_size(const node<T> * head){
    std::size_t counter = 0;
    for(const node<T> * p = head; p!= nullptr; p=p->link()){
        counter++;
    }
    return counter;
}

template <class T>
void list_head_insert(node<T> * &head, node<T> * &tail, const T &value){
    if(tail == nullptr){
        tail = head = new node<T>(value, head);
    }else{
        head = new node<T>(value, head);
    }
}

template <class T>
void list_tail_insert(node<T> * &head, node<T> * &tail, const T &value){
    if(head == nullptr){
        head = tail = new node<T>(value, nullptr);
    }else{
        tail->setlink(new node<T>(value, nullptr));
        tail=tail->link();
    }
}

template <class T>
std::ostream & operator <<(std::ostream & os, const node<T> * head){
    for(const node<T> *p = head; p!= nullptr; p=p->link()){
        os << p->data() << " ";
    }
    return os;
}

template <class T>
node<T> * list_search(node<T> *head, const T &value){
    for(node<T> *p = head; p!= nullptr; p=p->link()){
        if(p->data() == value){
            return p;
        }
    }
    return nullptr;
}

template <class T>
void list_copy(const node<T> *orig_head, const node<T> *orig_tail, node<T> * &new_head, node<T> * &new_tail){
    new_head = new_tail = nullptr;
    for(const node<T> *p = orig_head; p!= nullptr; p=p->link()){
        list_tail_insert(new_head, new_tail, p->data());
    }
}

template <class T>
void list_head_remove(node<T> * &head, node<T> * &tail){
    if(head == nullptr){
        return;
    }
    delete head;
    head = head->link();
    if(head == nullptr){
        tail = head;
    }

}

template <class T> 
void list_remove(node<T> * previous, node<T> * &tail){
    if(tail == nullptr){
        return;
    }
    if(previous->link() == tail){
        delete previous->link();
        tail = previous;
        previous->setlink(nullptr);
    }else{
        previous->setlink(previous->link()->link());
    }
}

template <class T>
void list_insert(node<T> * previous, const T & value){
    previous->setlink(new node<T>(value, previous->link()));
}

/////////////////////////////////////////////////////////////////

template <class T>
void list_clear(node<T> * &head_ptr, node<T> * &tail_ptr) {
    node<T> *p = head_ptr;
    while(p != nullptr) {
        head_ptr = p->link();
        delete p;
        p = head_ptr;
    }
}

template <class T>
void list_reverse(node<T> * &head_ptr, node<T> * &tail_ptr) {    
    node<T> *p = nullptr;
    node<T> *c = head_ptr;
    node<T> *n = nullptr;

    while (c!=nullptr) {
        n = c->link();
        c->setlink(p);
        p = c;
        c = n;
    }
    head_ptr = p;  
}

#endif // NODE_H