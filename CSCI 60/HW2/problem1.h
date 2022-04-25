#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>//ADT Style:  no using namespace std;
#include <iostream>
class Rational{

public:
    Rational(int n, int d);
    Rational();
    int numer(){  return numer_; }//ADT Style:give the getter the variable name minus the _
    int denom(){  return denom_; }//ADT Style:Don't bother with forward declaration for one-liner


    void operator *=(Rational b);


    void operator +=(Rational b);


  private:
      int numer_;//ADT Style: trailing _ means this is a private variable
      int denom_;
};
//pre: none
//post: returns a Rational that is the result of multiplying this Rational and the Rational passed in.
//The result is not reduced; the denominator will be the product of the denominators of the operands.
Rational operator *(Rational a, Rational b);

//pre: none
//post: returns a Rational that is the result of adding this Rational and the Rational passed in.
//The result is not reduced; the denominator will be the product of the denominators of the operands.
Rational operator +(Rational a, Rational b);
std::ostream& operator <<(std::ostream& out, Rational a);
//The problem was that I was missing the std:: in front of ostream

///////////////////////////////////////////////////////////////////////

//pre: none
//post: returns true if same, returns false if different
bool operator ==(Rational a, Rational b);


#endif
