#include "atm.h"
#include "bankaccount.h"

Atm::Atm() {
	twenties_ = 0;
	tens_ = 0;
}

Atm::Atm(int t20, int t10) {
	twenties_ = t20;
	tens_ = t10;
}

BankAccount Atm::get_cash(int amount, BankAccount b) {
	if (amount < b.balance) {
		int total = amount;
		if ((get_twenties() - total/20) < 0) {
			std::cout << "Not enough bills" << std::endl;
		} else {
			twenties_ = get_twenties() - total/20;
		}
		if (total % 20 != 0) {
			if ((get_tens() - 1) < 0) {
				std::cout << "Not enough bills" << std::endl;
			} else {
				tens_ = get_tens() - 1;
			}
		}
		b.balance = b.balance - (20 * get_twenties()) - (10 * get_tens());
		return b;
	} else {
		std::cout << "Invalid amount" << std::endl;
	} 
}

void Atm::operator +=(Atm& rhs) {
	twenties_ = get_twenties() + rhs.get_twenties();
	tens_ = get_tens() + rhs.get_tens();
}

void Atm::restock(int new20s, int new10s) {
	twenties_ += new20s;
	tens_ += new10s;
}

bool operator ==(Atm lhs, Atm rhs) {
	return (lhs.get_twenties() == rhs.get_twenties() && lhs.get_tens() == rhs.get_tens());
}

std::ostream& operator <<(std::ostream&out, Atm a) {
	out << "20 dollar bills: " << a.get_twenties() << std::endl;
	out << "10 dollar bills: " << a.get_tens() << std::endl;
	return out;
}