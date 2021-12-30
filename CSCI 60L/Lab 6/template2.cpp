#include<iostream>
#include<string>
using namespace std;

template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high)
{
  int count=0;
   for(T2 i=0;i<size;i++)
   {
     if(a[i]>=low&&a[i]<=high)
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
  string s2="b",s3="l";
  cout<<count_range(a,4,s2,s3)<<endl;
  cout<<count_range(arr,6,2,4)<<endl;
}
