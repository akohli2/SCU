
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
    void setdata_(const value_type & newdata_){
        data_ = newdata_;
    }
    void setlink_(node * newlink_){
        link_ = newlink_;
    }
private:
    value_type data_;
    node * link_;
};

// linked list toolkit functions

template <class T>
std::size_t list_size(const node<T> * head){
    std::size_t count = 0;
    for(const node<T> * p = head; p!=nullptr; p = p->link()){
        count++;
    }
    return count;
}
template <class T>
void list_head_insert(node<T>* & head,//call by reference node<T> pointer - so if you change head in the function, you change the head that was passed in
                      node<T>* & tail,
                      const T & value){
   head = new node<T>(value, head);
   if(tail == nullptr)
       tail = head;
}
template <class T>
void list_tail_insert(node<T> * & head,
                      node<T>* & tail,
                      const T & value){
    if(head==nullptr){
        head = tail = new node<T>(value, nullptr);
    }
    else{
        tail->setlink_(new node<T>(value, nullptr));
        tail = tail->link();
    }

}
template <class T>
std::ostream & operator << (std::ostream & os, const node<T> * head){
    for(const node<T> * p = head; p!=nullptr; p = p->link()){
        os<<"("<<p->data()<<", "<< (void *) (p->link())<<"), ";//NOT std::cout
    }
    return os;
}
template <class T>
node<T>* list_search(node<T>* head, const T & value){//Did this in lab
//If want it to work with const pointers, need const version also
    for(node<T> * p = head; p!=nullptr; p = p->link()){
        if(p->data()== value)
            return p;
    }
    return nullptr;
}
template <class T>
node<T>* list_locate(node<T>* head, std::size_t pos)//Did this in lab
{
    std::size_t i=0;
    node<T> * p;
    for(p = head; p!=nullptr &&i<pos; p = p->link()){
        i++;
    }
    return p;
}
template <class T>
void list_copy(const node<T> *orig_head,
               const node<T> *orig_tail,
               node<T> * & new_head,
               node<T> * & new_tail){
    new_head = new_tail = nullptr;
    for (const node<T>* p = orig_head; p!=nullptr; p = p->link()){
        list_tail_insert(new_head, new_tail, p->data());
    }

}
template <class T>
void list_remove(node<T> * previous, node<T> * &tail){
//Should pass in the tail so we can re-set it!
    node<T>* temp = previous->link();
    previous->setlink_(temp->link());
    if(temp==tail)
        tail = previous;
    delete temp;
}
template <class T>
void list_head_remove(node<T> * & head, node<T> * &tail){
    if(head == nullptr)
         return;
    node<T>* temp = head;
    head = head->link();
    delete temp;
    if(head==nullptr)
        tail = head;
}
//Remember, we already have head insert and tail insert
template <class T>
void list_insert(node<T> * previous, const T & value)
{
    previous->setlink_(new node<T>(value, previous->link()));
}
//Lucky you!  This one is homework.  What should it do?
//delete all the nodes in the linked list and end up with head and tail pointing to null

template <class T>
void list_clear(node<T> * & head, node<T> * & tail)
{
}
#endif // NODE_H
