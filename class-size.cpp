#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    string pin;
public:
    BankAccount(string name, double bal, string p) : 
        accountHolder(name), balance(bal), pin(p) {}
};

int main() {
    cout << "64-bit সিস্টেমে মেমরি সাইজ:" << endl;
    cout << "--------------------------------" << endl;
    cout << "std::string সাইজ: " << sizeof(string) << " bytes" << endl;
    cout << "double সাইজ: " << sizeof(double) << " bytes" << endl;
    cout << "pointer সাইজ: " << sizeof(void*) << " bytes" << endl;
    cout << "BankAccount ক্লাস সাইজ: " << sizeof(BankAccount) << " bytes" << endl;
    
    BankAccount acc("John Doe", 1000.0, "1234");
    
    // Memory alignment info
    cout << "\nMemory Alignment:" << endl;
    cout << "--------------------------------" << endl;
    cout << "string alignment: " << alignof(string) << " bytes" << endl;
    cout << "double alignment: " << alignof(double) << " bytes" << endl;
    cout << "BankAccount alignment: " << alignof(BankAccount) << " bytes" << endl;
    
    return 0;
}