#include<bits/stdc++.h>
using namespace std;

class BankAccount {
private:
	static double interestRate;
	double balance;

public:
	// BankAccount is a constructor
	BankAccount(double initialBalance) : balance(initialBalance) {
		cout << "Account created with initial balance: " << balance << " Taka" << "\n";
	}

	// static function- can only access static variables
	static void setInterestRate(double rate) {
		interestRate = rate;
		cout << "Interest rate set to: " << (rate * 100) << "%" << endl;
	}

	// non static function- can access static variables
	void addInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Interest added: " << interest << " Taka" << endl;
    }

    // getter method- non static variable
    double getBalance() {
        return balance;
    }
    
    // setter method- static variable
    static double getCurrentRate() {
        return interestRate;
    }
};

double BankAccount::interestRate = 0.5;

int main() {
	cout << "Default interest rate: " << (BankAccount::getCurrentRate() * 100) << "%" << endl;

	// first account
	BankAccount acc1(1000);
	cout << "Initial balance for acc1: " << acc1.getBalance() << " Taka" << endl;
	// add interest to first account
	acc1.addInterest();
    cout << "Balance after adding interest: " << acc1.getBalance() << " Taka" << endl;

    // change interest rate
     BankAccount::setInterestRate(0.06); // here i could use acc1 to change the value but it is recommendade to change static things with class name so that it can be easily understood by us that it is a static thing.

     // second account
     BankAccount acc2(2000);
    cout << "Initial balance for acc2: " << acc2.getBalance() << " Taka" << endl;
	// add interest to second account
    acc2.addInterest();
    cout << "Balance after adding interest: " << acc2.getBalance() << " Taka" << endl;
}
