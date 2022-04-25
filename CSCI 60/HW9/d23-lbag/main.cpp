#include <iostream>
#include "lbag.h"
#include "node.h"
using namespace std;

int main(int argc, char *argv[])
{
  LBag<int> b, d;
  b.insert(5);
  b.insert(2);
  b.insert(7);
  cout<<b<<endl; //725
  d = b;
  d.insert(1); 
  cout<<b<<endl; //725
  cout<<d<<endl; //1725




  LBag<int> a;
  a.insert(3);
  b += a; 
  cout << b << endl; //7253

  LBag<int> c;
  c = b + a;
  cout << c << endl; //72533

  cout << c.erase_one(2) << endl;
  cout << c << endl; //7533

  cout << c.erase(5) << endl; //1
  cout << c << endl; //733




    return 0;
}
