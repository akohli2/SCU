#include <iostream>
using namespace std;

int main() {
  char grade;
  cout << "Enter a grade: " << endl;
  cin >> grade;
  switch (grade) {
    case 'A' :
      cout << "Amazing job!" << endl;
      break;
    case 'B' :
      cout << "Great work!" << endl;
      break;
    case 'C' :
      cout << "You pass, good job." << endl;
      break;
    case 'D' :
      cout << "You pass, but barely." << endl;
      break;
    case 'F' :
      cout << "You need to improve!!" << endl;
      break;
    default :
      cout << "That's not a valid grade" << endl;
  }
  return 0;
}
