#include <iostream>
using namespace std;
int main() {
	if(36) { //if 36 != 0
		cout << "36 is true!" << endl;
	} else {
		cout << "36 is false!" << endl;
	}
	if(0) { //if 0 != 0
		cout << "0 is true!" << endl;
	} else {
		cout << "0 is false!" << endl;
	}
	if(!(5<=4+1)) {
		cout << "!5<=4+1 is true" <<endl;
	} else {
		cout << "!5<=4+1 is false" <<endl;
	}
	if((-1)<0<1) {
		cout << "-1<0<1 is true" <<endl;
	} else {
		cout << "-1<0<1 is false" <<endl;
	}
	int x = 0;
	if(x==5) {
		cout << "x=5 is true" <<endl;
	} else {
		cout << "x=5 is false" <<endl;
	}
	bool condition;
	condition = (6<7);
	if(!(condition)) {
		cout << "!(6<7) is true!" << endl;
	} else {
		cout << "!(6<7) is false!" << endl;
	}
	if(true || false){
		cout << "true || false is true" <<endl;
	} else {
		cout << "true || false is false" <<endl;
	}
	if(true || true) {
		cout << "true || true is true" <<endl;
	} else {
		cout << "true || true is false" <<endl;
	}
	return 0;
}

//36 is true!
//0 is false!
//!5<=4+1 is false
//-1<0<1 is false
//x=5 is false
//!(6<7) is false!
//true || false is true
//true || true is true
