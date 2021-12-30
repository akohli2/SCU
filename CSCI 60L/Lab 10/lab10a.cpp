#ifndef BAG_H
#define BAG_H

#include <cstdlib>
#include <cassert>
#include <algorithm>


template <class T>
class bag_iterator{

public:
    bag_iterator(T *initial = nullptr) {
        current = initial;
    }

    T operator *() const {
        return *current;
    }

    // returns THIS iterator, not a copy of it
    // this is the meaning of &
    bag_iterator & operator ++() // pre-increment
    {
        current = current+1;
        return *this;
    }

    bag_iterator operator ++(int) // post-increment
    {
        bag_iterator temp =  *this;
        current = current+1;
        return temp;
    }

    bool operator == (const bag_iterator other) const {
        return (current == other.current);
    }

    bool operator != (const bag_iterator other) const {
        return (current != other.current);
    }


private:
    T* current;
};






// WANT: a template class bag<T> to store a collection of items
//       of type T(multiple copies are allowed)
//       there is a FIXED limit on how many elements can be in a
//       bag<T> called CAPACITY (same for every bag<T>)

// Supported operations:
//        size (number of elements in bag), count number of times
//        a value appears in bag insert, delete, find

template <class T>
class bag
{
public:

    // CONSTANTS and TYPES



    // std::size_t is a pre-defined type for unsigned int
    // guaranteed to use the maximum storage allowed on
    // your machine
    typedef std::size_t size_type;

    //typedef for iterator class goes here

    typedef bag_iterator<T> iterator;

    // known outside class as bag<T>::CAPACITY
    static const size_type CAPACITY = 100;



    // CONSTRUCTOR

    // pre: none
    // post: creates an initially empty bag
    bag();
    bag(T arr[], size_type size);

    // CONSTANT MEMBER FUNCTIONS

    // pre: none
    // post: returns the number of elements stored in this bag
    size_type size() const;

    // pre: none
    // post: if target appears in this bag, returns the number of times it appears
    //       else, returns 0
    size_type count(const T & target) const;


    // MODIFICATION (MUTATOR) MEMBER FUNCTIONS

    // pre: size() < CAPACITY
    // post: a copy of target has been added to this bag
    void insert(const T & target);

    // pre: size() + b.size() <= CAPACITY
    // post: adds a copy of each element of b to this bag
    void operator += (const bag & b);


    iterator begin() {
        return (data_);
    }
    iterator end() {
        return (data_+size_);
    }

private:

    T data_[CAPACITY];
    size_type  size_;

    // INVARIANTS:

    // data_[0], data_[1], ..., data_[size_-1] contain the elements in this bag
    // don't care about values in data_[size_], ..., data_[CAPACITY-1]

};



template <typename T>
bag<T>::bag(){
    size_ = 0;
}

template <typename T>
bag<T>::bag(T arr[], size_type size){
    for(size_type i = 0; i<size; ++i)
        data_[i] = arr[i];
    size_ = size;
}

template <typename T>
typename bag<T>::size_type bag<T>::size() const{
    return size_;
}

template <typename T>
typename bag<T>::size_type bag<T>::count(const T & target) const{
    size_type counter = 0;
    for(size_type i=0; i<size_; i++){
       if(target == data_[i])
           counter++;
    }
    return counter;
}

template <typename T>
void bag<T>::insert(const T & target){
    assert(size_<CAPACITY);
    data_[size_] = target;
    size_++;
}

template <typename T>
void bag<T>::operator += (const bag<T> & b){
    assert(size_+b.size_ <= CAPACITY);

    for(size_type i = 0; i<b.size(); i++){
        insert(b.data_[i]);
    }
}


int main() {
    bag<int> b;
    b.insert(5);
    b.insert(4);
    b.insert(3);
    b.insert(2);
    b.insert(1);

    for (auto i : b) {
        cout << i << endl;
    }
    cout << endl;
    for (bag<int>::iterator j = b.begin(); j != b.end(); j++) {
        cout << *j << endl;
    }
    return 0;
}

#endif