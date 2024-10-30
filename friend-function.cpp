#include<bits/stdc++.h>
using namespace std;

class BankAccount {
private:
	double balance;

public:
	BankAccount(double balance) : balance(balance) {};
	friend void displayBalance(const BankAccount &bankAccount);
};

void displayBalance(const BankAccount &bankAccount) {
	cout << "Current Balance: " << bankAccount.balance << "\n";
}

int main() {
	BankAccount account(1000.0);
	displayBalance(account);
	return 0;
}