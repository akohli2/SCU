#include <iostream>
#include <cmath>

using namespace std;

class complex {
private:
	double real;
	double imaginary;
public:
	double get_real() {return real;}
	double get_imaginary() {return imaginary;}
	complex();
	complex(double r, double i);
	double magnitude();
};

complex::complex() {
	real = 0;
	imaginary = 0;
}

complex::complex(double r, double i) {
	real = r;
	imaginary = i;
}

double complex::magnitude() {
	return sqrt(real*real + imaginary*imaginary);
}

complex operator +(complex c1, complex c2) {
	double a = c1.get_real() + c2.get_real();
	double b = c1.get_imaginary() + c2.get_imaginary();
	complex c3(a, b);
	return c3;
} 

bool operator ==(complex c1, complex c2) {
	return (c1.get_real() == c2.get_real() && c1.get_imaginary() == c2.get_imaginary());
}

ostream& operator <<(ostream& out, complex c) {
	out << c.get_real() << " + " << c.get_imaginary() << "i";
	return out;
}

int main() {
	complex c1(1, 2);
	complex c2(3, 4);
	cout << (c1+c2) << endl;
	cout << (c1==c2) << endl;
	cout << c1.magnitude() << endl;
	cout << c1.get_real() << endl;
}

