#ifndef LBAG_H
#define LBAG_H

#include <cstdlib>
#include <ostream>
#include "node.h"

template <class T>
class LBag
{
public:
    typedef T value_type;
    typedef std::size_t size_type;

    // pre: none
    // post: creates an empty LBag
    LBag();

    // pre: none
    // post: creates an LBag that is a copy of given LBag
    LBag(const LBag &);

    //Returns all memory to the runtime environment and sets head and tail to nullptr
    ~LBag();

    //pre: none
    //post:  change this bag to be a copy of the parameter bag
    void operator =(const LBag &);

    //pre: none
    //post:  returns the number of nodes in the linked list
    size_type size() const;

    //pre: none
    //post:  returns the number of times the parameter value appears in the bag
    size_type count(const T &) const;

    //pre: none
    //Post:  the parameter value is inserted at the head of the bag
    void insert(const T &);

    //pre: none
    //post:  our bag includes all of its elements, followed by all of the parameter bag's elements
    void operator +=(const LBag &);//homework

    //pre: none
    //post:  removes the first instance of the parameter value in the bag, if there is one.
    bool erase_one(const T &);//homework

    //pre: none
    //post:  removes all instances of the parameter value in the bag.
    size_type erase(const T &);//homework

    T begin();
    T end();

    template <class T2>//Don't use class's type variable, because this is NOT part of the class
    friend std::ostream& operator <<(std::ostream& out, const LBag<T2> &);

private:
    node<T> *head, *tail;
};



template <class T>
LBag<T>::LBag(){
  tail = nullptr;
  head = tail;
}


template <class T>
LBag<T>::LBag(const LBag<T> & b){
  list_copy(b.head, b.tail, head, tail);
}

template <class T>
LBag<T>::~LBag(){
  list_clear(head, tail);
}

template <class T>
void LBag<T>::operator =(const LBag<T> & b){
    list_clear(head, tail);
    list_copy(b.head, b.tail, head, tail);
}


template <class T>
typename LBag<T>::size_type LBag<T>::size() const{
  return list_size(head);
}


template <class T>
typename LBag<T>::size_type LBag<T>::count(const T & value) const{
  size_type count = 0;
  node<T>* p = list_search(head, value);
  while(p!=nullptr){
    p = list_search(p->link(), value);
    ++count;
  }
  return count;

}

template <class T>
void LBag<T>::insert(const T & value){
  list_head_insert(head, tail, value);
}



template <class T>
std::ostream& operator <<(std::ostream& out, const LBag<T> & b){
  out<<b.head;
  return out;
}

template <class T>
void LBag<T>::operator +=(const LBag<T> & b) {
	for (node<T> *p = b.head; p!=nullptr; p=p->link()) {
		list_tail_insert(head, tail, p->data());
	}
}

template <class T>
LBag<T> operator +(const LBag<T> & b1, const LBag<T> & b2) {
	LBag<T> sum;
	sum+=b1;
	sum+=b2;
	return sum;
}

template <class T>
bool LBag<T>::erase_one(const T & value) {
	node<T> *prev = head;
	node<T> *current = head->link();
	node<T> *next = head->link()->link();
	if(prev->data() == value) {
		if(head == nullptr) {
			return;
		}
	    node<T>* temp = head;
	    head = head->link();
	    delete temp;
	    if(head == nullptr) {
	    	tail = head;
	    }
		return true;
	}
	while(current->data() != value) {
		prev->link();
		current->link();
		next->link();
	}
	if (current->data() == value) {
		prev->setlink(next);
		delete current;
		return true;
	}
	return false;
}

template <class T>
std::size_t LBag<T>::erase(const T & value) {
	std::size_t count = 0;
	while(erase_one(value) == true) {
		count++;
	}
	return count;
}


#endif // LBAG_H
