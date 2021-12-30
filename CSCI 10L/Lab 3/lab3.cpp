#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int y0;
  int o;
  int v;
  double g = 9.81;
  cout << "Enter values y0, o, and v" << endl;
  cin >> y0 ;
  cin >> o;
  cin >> v;

  //while loop

  int x = 0;
  while (x <= 9) {
	  double y = y0 + ( x * tan(o) ) - ( ( g * pow(x,2) ) / (2 * pow(v*cos(o),2) ) );
      cout << "(" << x << "," << y << ")" << endl;
	  x++;
  } 

  //for loop

  // for(int x = 0; x <= 9; x++) {
  //   double y = y0 + ( x * tan(o) ) - ( ( g * pow(x,2) ) / (2 * pow(v*cos(o),2) ) );
  //   cout << "(" << x << "," << y << ")" << endl;
  // }
  // return 0;
}
