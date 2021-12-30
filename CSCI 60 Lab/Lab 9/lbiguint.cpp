#include "lbiguint.h"
#include "node2.h"

#include <cassert>
#include <sstream>
#include <iostream>

using namespace std;

 lbiguint::lbiguint() {
    head = tail = new node(0, nullptr);
 }
 lbiguint::lbiguint(const std::string & s) {
    head = tail = nullptr;
    for (int i = 0; i < s.size(); i++) {
        if (tail == nullptr) {
            head = tail = new node(s[i]-'0', nullptr);
        } else {
            head = new node (s[i]-'0', head);
        }
    }
 }

lbiguint::~lbiguint() {
    node *p = head;
    while (p != nullptr) {
        node *temp = p;
        p=p->link();
        delete temp;
    }
    head = tail = nullptr;
}

std::size_t lbiguint::size() const {
    std::size_t count = 0;
    for (node *p = head; p!=nullptr; p=p->link()) {
        count++;
    }
    return count;
}

int lbiguint::operator [](std::size_t pos) const {
    size_t count = 0;
    for (node *p = head; p!= nullptr; p=p->link()) {
        if (count == pos) {
            return p->data();
        }
        count++;
    }
    return 0;
}

std::ostream & operator << (std::ostream & os, const lbiguint & l) {

    for (int i = l.size()-1; i > 0; i--) {
        os << l[i];
    }
    os << l[0];
    cout << endl;
    return os;
}

void lbiguint::operator =(const lbiguint & l) {
    node *p = head;
    while(p != nullptr) {
        head = p->link();
        delete p;
        p = head;
    }
    node *q = l.head;
    for (node *p = head; p!=nullptr; p=p->link()) {
        if (p == nullptr) {
            p = tail = new node(q->data(), nullptr);
        } else {
            tail->set_link(new node(q->data(), nullptr));
            tail = tail->link();
        }
        q = q->link();
    }
}


 // unsigned short lbiguint::operator [](std::size_t pos) const
 // {
 //     assert(pos < CAPACITY);
 //     return _data[pos];
 // }   1`



 // int lbiguint::compare(const lbiguint & b) const{
 //     for(std::size_t i =CAPACITY-1; i>=0; --i){
 //         if(_data[i]>b._data[i])
 //             return 1;
 //         else if (_data[i]<b._data[i])
 //             return -1;

 //     }
 //     return 0;
 // }



 // void lbiguint::operator += (const lbiguint & b){
 //     int carry = 0;
 //     int next = 0;
 //     for(std::size_t i=0; i<CAPACITY; ++i){
 //         next = carry+_data[i]+b._data[i];
 //         _data[i]=next%10;
 //        carry=next/10;
 //     }
 // }
 // std::string lbiguint::toStdString() const
 // {
 //     std::stringstream ss;
 //     ss << *this;
 //     return ss.str();
 // }//We haven't talked about stringstreams; just ignore this, I was being lazy.
 // std::ostream & operator << (std::ostream & os, const lbiguint & b)
 // {

 //     for (int i = lbiguint::CAPACITY - 1; i >= 0; --i)
 //         os << b[i];
 //     return os;
 // }

 // std::istream & operator >> (std::istream & is, lbiguint & b)
 // {
 //     std::string s;
 //     is >> s;
 //     b = lbiguint(s);
 //     return is;


 // }

 // bool operator <(const lbiguint& a, const lbiguint& b){
 //     return (a.compare(b)==-1);
 // }

 // bool operator <= (const lbiguint & b1, const lbiguint & b2)
 // {
 //     return (b1.compare(b2) <= 0);
 // }

 // bool operator == (const lbiguint & b1, const lbiguint & b2)
 // {
 //     return (b1.compare(b2) == 0);
 // }

 // bool operator != (const lbiguint & b1, const lbiguint & b2)
 // {
 //     return (b1.compare(b2) != 0);
 // }

//You do > and >=