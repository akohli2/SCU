#include<iostream>
#include<string>
using namespace std;

// T1 should have the find operator
// T2 has to have ++ defined and should be able to be asigned 0
template <typename T1, typename T2>
T2 count_exact(T1 a[], T2 size, T1 find)
{
  T2 count=0;
  for(T2 i=0; i<size;i++)
  {
    if(a[i]==find)
    {
      count+=1;
    }
  }
  return count;
}

int main()
{
  int arr[]={6,2,3,2,6,2};
  string a[]={"arjun","farah","arjun","ishita"};
  string s="arjun";
  cout<<count_exact(a,4,s)<<endl;
  cout<<count_exact(arr,6,2)<<endl;
}
