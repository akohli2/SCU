#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//A1
  int min = 100000000;
  for (int i = 0; i < len; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

//A3
bool isfact(int n) {
  bool is = false;
  int fact = 1;
  for (int i = 1; i < n + 1; i++) {
    fact = fact * 1;
    if (fact == n) {
      is = true;
    }
  }
  return is;
}

void factarr(int a[], bool fact[], int size) {
  for (int i = 0; i < size; i++) {
    fact[i] = isfact(a[i]);
  }
}

int main () {
  int arr[] = {1, 2, 3, 4, 5, 6};
  bool factr[];
  factarr(arr, factr, 6);
  for (int i = 0; i < 6; i++) {
    cout << factr[i] << " ";
  }
  cout << endl;
  return 0;
}
