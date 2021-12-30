#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // CONSTANTS & TYPES

    static const std::size_t CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint();

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const std::string &);

    // CONSTANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint & b) const;



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint & b);
    void operator -= (const biguint & b);



    // pre: none
    // post: b returned as a string
    std::string toString();

private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions
std::ostream& operator <<(std::ostream& out, const biguint& b);
biguint operator + (const biguint & b1, const biguint & b2);
biguint operator - (const biguint & b1, const biguint & b2);

bool operator < (const biguint & b1, const biguint & b2);
bool operator <= (const biguint & b1, const biguint & b2);
bool operator != (const biguint & b1, const biguint & b2);
bool operator == (const biguint & b1, const biguint & b2);
bool operator >= (const biguint & b1, const biguint & b2);
bool operator > (const biguint & b1, const biguint & b2);





#endif // BIGUINT_H