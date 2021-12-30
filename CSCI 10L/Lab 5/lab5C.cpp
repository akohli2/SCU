// Part A)
//
// #include <iostream>
// using namespace std;
//
// int fun(int c, int b);
//
// int main(){
// 	int a = 0, b= 5, c = 10;
// 	cout<<"a is: "<<a<<" b is: "<<b<<" c is: "<<c<<endl; // a is: 0, b is: 5, c is: 10
// 	b=fun(a, c); //a is: 0, b is: 20, c is: 21
// 	cout<<"a is: "<<a<<" b is: "<<b<<" c is: "<<c<<endl; // a is: 0, b is: 21, c is: 10
// 	while(b==21) {
// 		int a = 3;
// 		b = a;
// 		cout<<"a is: "<<a<<" b is: "<<b<<" c is: "<<c<<endl; // a is: 3, b is: 3, c is: 10
//     }
//     cout<<"a is: "<<a<<" b is: "<<b<<" c is: "<<c<<endl; // a is: 0, b is: 3, c is: 10
//     return 0;
// }
//
// int fun(int c, int b){
//     b = 2*b;
//     c = b+1;
//     cout<<"a is: " << a <<" b is: "<<b<<" c is: "<<c<<endl; //no variable a in fun; either have to take out or declare a
//     return c;
// }


#include <iostream>
using namespace std;

void beans(int y, int& n, int size);

void spam(int& n, int& y);

int main(){
	int m = 7;
    int n = 4;
    cout<<"m is "<<m<<" n is "<<n<<endl; //m is 7, n is 4
    beans(n, m, 3);
    cout<<"m is "<<m<<" n is "<<n<<endl; //m is 14, n is 4
    spam(m, n);
    cout<<"m is "<<m<<" n is "<<n<<endl; //m is 28, n is 14
    spam(n, n);
    cout<<"m is "<<m<<" n is "<<n<<endl; //m is 28, n is 28
    beans(m, 2, n);
    cout<<"m is "<<m<<" n is "<<n<<endl; //m is 28, n is 28
    return 0;
}

void beans(int y, int& n, int size){
	y = n+size;
    n = 7+n;
}

void spam(int& n, int& y){
    int m = n+y;
    y=n;
    n=y+n;
}



// Part C)
//
// #include <iostream>
//
// using namespace std;
//
// void MaxAndAverage(double& avg, double& max) {
//   double val = 0;
//   double total = 0;
//   double count = 0;
//   avg = 0;
//   max = -1;
//   cout << "Please enter a value, or -1 when you're done." << endl;
//   cin >> val;
//   while (val != -1) {
//     total = total + val;
//     count++;
//     if (val > max) {
//       max = val;
//     }
//     cout << "Please enter a value, or -1 when you're done." << endl;
//     cin >> val;
//   }
//   avg = total/count;
// }
//
// int main() {
//   double a, b;
//   MaxAndAverage(a, b);
//   cout << avg << " " << max;
// }
