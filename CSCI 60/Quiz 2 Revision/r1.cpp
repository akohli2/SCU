#include <iostream>

template <class T1, class T2>
class Pair {
public:
	T1 first;
	T2 second;
	Pair(T1 f, T2 s);
};

template <class T1, class T2>
Pair<T1, T2>::Pair(T1 f, T2 s) {
	first = f;
	second = s;
}

template <class T1, class T2>
bool operator <(Pair<T1, T2> & a, Pair<T1, T2> & b) {
	return ((a.first < b.first) || (a.first == b.first && a.second < b.second));
}

template <class T1, class T2>
std::ostream & operator <<(std::ostream & out, Pair<T1, T2> p) {
	out << "(" << p.first << ", " << p.second << ")" << std::endl;
	return out;
}

int main() {
	Pair<int, double> p1(1, 5.5);
	Pair<int, double> p2(2, 6.5);
	std::cout << p1 << std::endl;
	std::cout << p1<p2 << std::endl;
}


