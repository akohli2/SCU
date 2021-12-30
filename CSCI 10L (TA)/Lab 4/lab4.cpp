#include <iostream>

using namespace std;


//1. Print "x" 50 times

//x x x x x
//x x x x x
//x x x x x
//x x x x x
//x x x x x
//x x x x x
//x x x x x
//x x x x x
//x x x x x
//x x x x x

//2. Print "x" 50 times

//x x x x x x x x x x
//x x x x x x x x x x
//x x x x x x x x x x
//x x x x x x x x x x
//x x x x x x x x x x

//3. Print "x"

//o x x x x x x x x x
//x o x x x x x x x x
//x x o x x x x x x x
//x x x o x x x x x x
//x x x x o x x x x x
//x x x x x o x x x x
//x x x x x x o x x x
//x x x x x x x o x x
//x x x x x x x x o x
//x x x x x x x x x o

//4.

// int main() {
//   for (int i = 0; i < 5; i++) {
//     for (int j = 3; j > 0; j--) {
//       cout << i*j << " ";
//     }
//   }
// }



int die (int n) {
  cout << ((rand() %n) + 1) << endl;
  return 0;
}

int main() {
  srand(time(0));
  int n;
  cin >> n;
  die(n);
}

bool is_even (int n) {
  if (n % 2 == 0) {
    return true;
  }
  else {
    return false;
  }
}

int evens_between (int n, int m) {
  int count = 0;
  for (int i = n; i <= m; i++) {
    if (is_even(i) == true) {
      count ++;
    }
  }
  return count;
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << evens_between(n, m) << endl;
}
