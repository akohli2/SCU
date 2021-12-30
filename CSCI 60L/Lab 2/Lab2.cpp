#include <iostream>

using namespace std;

class ModInt {
public:
	ModInt();
	ModInt(int song, int skip);

	int get_playlist() {
		return playlist;
	}
	int get_skip() {
		return numSkip;
	}

	void operator +=(ModInt rhs);

private:
	int playlist;
	int numSkip;
};

bool operator ==(ModInt lhs, ModInt rhs) {
	if (lhs.get_playlist() == rhs.get_playlist() && lhs.get_skip() == rhs.get_skip()) {
		return true;
	}	
	return false;
}

ModInt::ModInt() {
	playlist = 1;
	numSkip = 0;
}
ModInt::ModInt(int song, int skip) {
	playlist = song;
	numSkip = skip;
}

void ModInt::operator +=(ModInt rhs) {
	if (playlist == rhs.get_playlist()) {
		numSkip = numSkip + rhs.get_skip();
		numSkip = numSkip % playlist;
		cout << numSkip;
	}
	else {
		playlist = -1;
		cout << playlist;
	}
}

ModInt operator +(ModInt lhs, ModInt rhs) {
	ModInt m(lhs.get_playlist(), lhs.get_skip());
	m += rhs;
	return m;
}



int main() {
	int pl = 9;
	int sk = 7;

	ModInt m1 = ModInt(pl, sk);
	cout << m1.get_playlist() << endl;
	cout << m1.get_skip() << endl;

	ModInt m2 = ModInt(pl, sk);

	cout << (m1 == m2) << endl;

	(m1 += m2);

	ModInt m = (m1 + m2);

}

