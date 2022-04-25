#ifndef ATM_H
#define ATM_H

class Atm {
private:
	int twenties_;
	int tens_;
public:
	Atm(int t20, int t10);
	//Pre: t20 >= 0, t10 >= 0
	//Post: Sets twenties_ = t20, tens_ = t10
	Atm();
	//Pre: None
	//Post: Sets twenties_ = 0, tens_ = 0
	int get_twenties() {return twenties_;}
	//Pre: None
	//Post: Returns twenties_
	int get_tens() {return tens_;}
	//Pre: None
	//Post: Returns tens_
	BankAccount get_cash(int amount, BankAccount b);
	//Pre: amount < (20*twenties_ + 10*tens_), amount < balance
	//Post: balance - amount, twenties_ - total/20, tens_ - 1
	void operator +=(Atm& rhs);
	//Pre: rhs.get_twenties() >= 0, rhs.get_tens() >= 0
	//Post: twenties_ += rhs.get_twenties(), tens_ += rhs.get_tens()
	void restock(int new20s, int new10s);
	//Pre: new20s >= 0, new10s >= 0
	//Post: Adds new20s to twenties_, Adds new10s to tens_
};

bool operator ==(Atm lhs, Atm rhs);

std::ostream& operator <<(std::ostream& out, Atm a);

#endif