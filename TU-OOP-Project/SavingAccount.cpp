#include "BankAccount.cpp"
#include <iostream>
#include <string>

using namespace std;

class SavingAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingAccount(int accNum, const string& holder, double bal, double rate)
        : BankAccount(accNum, holder, bal), interestRate(rate) {}

    void addInterest() {
        double interest = getBalance() * interestRate / 100;
        deposit(interest);
    }

    void toString() const override {
        BankAccount::toString();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};
