#include <iostream>
#include <cmath>
using namespace std;


//A2
// int findMin(int a[ ], int aSize){
//   int min = a[0];

//   for(int i = 1; i < aSize; i++){
//     if(a[i] < min){
//       min = a[i];
//     }
//   }
//   return min;
// }

bool isfact(int n)
{
 bool is=false;
 int fact=1;
 for(int i=1; i<n+1; i++){
 fact=fact*i;
 if(fact==n)
 is=true;
 }
 return is;
} 


void factarr(int a[], bool fact[], int size)
{
	for(int i = 0; i < size; i++) 
	{
		fact[i] = isfact(a[i]);
	}
}

void factors(int n, int facts[]) 
{
	facts[0] = 0;
	for(int i = 1; i <= n + 1; i++) 
	{
		if((n % i) == 0)
		{
			facts[i] = 1;
		}
		else facts[i] = 0;
	}
}

int main() {

	// A2
	// int aSize;
	// cout << "Enter array size: " << endl;
	// cin >> aSize;
	// int a[aSize];

	// for(int i = 0; i < aSize; i++) 
	// {
	// 	cout << "Enter an int: " << endl;
	// 	cin >> a[i];
	// }

	// cout << findMin(a, aSize) << endl;
	// int num;
	// cout << "Enter a number: " << endl;
	// cin >> num;
	// cout << isfact(num) << endl;

	// int aSize;
	// cout << "Enter the size of the array: " << endl;
	// cin >> aSize;
	// int a[aSize];
	// bool fact[aSize];
	// for(int i = 0; i < aSize; i++) 
	// {
	// 	cout << "Enter an integer: " << endl;
	// 	cin >> a[i];
	// }

	// factarr(a, fact, aSize);
	// for(int i = 0; i < aSize; i++) 
	// {
	// 	cout << fact[i] << " ";
	// }
	// cout << endl;
	
	int num;
	cout << "Enter a number: " << endl;
	cin >> num;
	int facts[num + 1];
	factors(num, facts);
	for(int i = 0; i <= num; i++)
	{
		cout << i << "    " << facts[i] << endl;
	}


	return 0;
}


