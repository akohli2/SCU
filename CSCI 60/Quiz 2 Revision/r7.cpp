#include <iostream>

using namespace std;

bool appears(int arr[], int assize, int find[], int fsize) {
	if(assize == 0) {
		return (fsize==0);
	} else {
		if (arr[assize-1]==find[fsize-1]) {
			return appears(arr, assize-1, find, fsize-1);
		} else {
			return appears(arr, assize-1, find, fsize);
		}
	}
} 