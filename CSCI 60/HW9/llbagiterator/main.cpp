#include <iostream>
#include "lbag.h"
#include "node.h"
using namespace std;

int main(int argc, char *argv[])
{
lbag<int> var;
var.insert(4);
var.insert(7);
var.insert(1);
cout<<var<<endl<<endl;



for(auto e:var)
    cout<<e<<endl;
cout<<endl;
//The above loop expands into the below loop
lbag<int>::iterator i;
for(i = var.begin(); i!=var.end(); ++i){
    cout<<(*i)<<endl;
}
    return 0;
}
