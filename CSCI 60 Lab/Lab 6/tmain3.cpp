#include<iostream>
#include<string>
#include "template3.h"
using namespace std;

int main()
{
  string r[]={"arjun","farah","arjun","ishita"};
  template3<string> a;
  template3<string> b(3);
  template3<string> c(4,r);
  b=c;
  cout<<b.index(r,3)<<endl;
  return 0;
}
