#ifndef LBIGUINT_H
#define LBIGUINT_H


#include <cstdlib>
#include <string>

class lbiguint
{
public:
    // pre: none
    // post: creates a linked list bigint with default value
    //       (default = 0)
    lbiguint();

    // pre:
    //      s[0], ..., s[s.size()-1] are digits
    // post: creates a lbiguint whose digits are given in s
    lbiguint(const std::string & s);


    // pre: none
    // post: returns dynamically allocated memory to heap
    ~lbiguint();

    // pre: none
    // post: returns the number of nodes of this lbiguint
    std::size_t size() const;

    // pre: none
    // post: makes this linked list biguint a copy of given linked list biguint
    void operator =(const lbiguint &);

    // pre: none
    // post: returns the digit at given pos (0 if does not exist)
    //       pos 0 is the least significant (units) digit
    int operator [](std::size_t pos) const;

    // pre: none
    // post: returns 0 if this lbiguint equals given lbiguint
    //               1 if this lbiguint >      given lbiguint
    //              -1 otherwise
    int compare(const lbiguint &) const;


    // pre: none
    // post: adds/subtracts given lbiguint to this lbiguint
    void operator +=(const lbiguint &);
    void operator -=(const lbiguint &);
    void operator *=(const lbiguint &);

private:
    node *head, * tail;

    // INVARIANTS:
    //    head points to the ones place node in the linked list

};


// nonmember functions

bool operator < (const lbiguint &, const lbiguint &);
bool operator <= (const lbiguint &, const lbiguint &);
bool operator == (const lbiguint &, const lbiguint &);
bool operator != (const lbiguint &, const lbiguint &);
bool operator >= (const lbiguint &, const lbiguint &);
bool operator > (const lbiguint &, const lbiguint &);

lbiguint operator +(const lbiguint &, const lbiguint &);
lbiguint operator -(const lbiguint &, const lbiguint &);
lbiguint operator *(const lbiguint &, const lbiguint &);

std::ostream & operator << (std::ostream &, const lbiguint &);





#endif // LBIGUINT_H