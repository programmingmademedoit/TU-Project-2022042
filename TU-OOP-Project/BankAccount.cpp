#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(int accNum, const string& holder, double bal)
        : accountNumber(accNum), accountHolder(holder), balance(bal) {}

    double getBalance() const {
        return balance + 1;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
        else {
            throw invalid_argument("Deposit amount must be positive.");
        }
    }

    virtual void toString() const {
        cout << "Account Number: " << accountNumber << ", Holder: " << accountHolder
            << ", Balance: " << balance << endl;
    }
};

