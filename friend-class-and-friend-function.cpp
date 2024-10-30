#include<bits/stdc++.h>
using namespace std;

class BankAccount {
private:
	string accountHolder;
	double balance;
	string pin;

	friend class TransectionManager;
	friend void checkBalance(BankAccount &bankAccount);

public:
	BankAccount(string name, double initialBalance, string initialPin) {
		accountHolder = name;
		balance = initialBalance;
		pin = initialPin;
	}
};

class TransectionManager {
public:
	void transferMoney(BankAccount &from, BankAccount &to, double amount) {
		if (from.balance >= amount) {
			from.balance -= amount;
			to.balance += amount;
			cout << "Transection successfull" << "\n";
			cout << "Sender " << from.accountHolder << "'s new balance: " << from.balance << "\n";
			cout << "Receiver " << to.accountHolder << "'s new balance: " << to.balance << "\n";
		} else {
			cout << "Insufficient balance" << "\n";
		}
	}
};

void checkBalance(BankAccount &bankAccount) {
	cout << "Account holder: " << bankAccount.accountHolder << "\n";
	cout << "Current balance: " << bankAccount.balance << "\n";
}

int main() {
	BankAccount karim("karim", 1000, "1234");
	BankAccount rahim("rahim", 5000, "2544");

	TransectionManager manager;
	cout << "Before transectoion: " << "\n";
	checkBalance(karim);
	checkBalance(rahim);

	manager.transferMoney(karim, rahim, 200);

	cout << "\nAfter transection: " << "\n";
	checkBalance(karim);
	checkBalance(rahim);

	return 0;
}