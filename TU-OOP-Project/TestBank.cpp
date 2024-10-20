#include "SavingAccount.cpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <string>

using namespace std;

bool isValidNumber(const string& input) {
    bool decimalPoint = false;
    for (char ch : input) {
        if (!isdigit(ch)) {
            if (ch == '.' && !decimalPoint) {
                decimalPoint = true;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool isValidAccountNumber(const string& accNumStr) {
    return accNumStr.length() == 3 && isValidNumber(accNumStr);
}

bool isValidHolder(const string& holder) {
    return (holder.length() >= 8 && holder.length() <= 30) && !isValidNumber(holder);
}

int main() {
    vector<SavingAccount> accounts;

    for (int i = 0; i < 5; i++) {
        string accNumStr, balStr, rateStr;
        int accNum;
        string holder;
        double bal;
        double rate;

        cout << "Enter details for account " << i + 1 << ":\n";
        cout << "Account Number (3 digits): ";
        cin >> accNumStr;
        cin.ignore();

        cout << "Account Holder: ";
        getline(cin, holder);

        cout << "Initial Balance: ";
        cin >> balStr;
        cout << "Interest Rate (%): ";
        cin >> rateStr;

        try {
            if (!isValidAccountNumber(accNumStr))
                throw invalid_argument("Account number must be exactly 3 digits.");
            if (!isValidHolder(holder))
                throw invalid_argument("Account holder must be between 8 and 30 characters and cannot contain any digits.");
            if (!isValidNumber(balStr))
                throw invalid_argument("Balance must be a valid number.");
            if (!isValidNumber(rateStr))
                throw invalid_argument("Interest rate must be a valid number.");

            accNum = stoi(accNumStr);
            bal = stod(balStr);
            rate = stod(rateStr);

            if (bal < 0) throw invalid_argument("Balance cannot be negative.");
            if (rate > 100) throw invalid_argument("Interest rate cannot be more than 100%.");
            if (rate < 0) throw invalid_argument("Interest rate cannot be negative.");

            accounts.emplace_back(accNum, holder, bal, rate);
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
            i--;
        }
    }

    cout << "\nInitial Account Information:\n";
    for (const auto& account : accounts) {
        account.toString();
    }

    accounts[0].deposit(300);
    accounts[1].deposit(300);
    for (int i = 2; i < 5; i++) {
        accounts[i].deposit(500);
    }

    cout << "\nAccount Information after Deposits:\n";
    for (const auto& account : accounts) {
        account.toString();
    }

    for (auto& account : accounts) {
        account.addInterest();
    }

    cout << "\nAccount Information after Adding Interest:\n";
    double totalBalance = 0;
    for (const auto& account : accounts) {
        account.toString();
        totalBalance += account.getBalance();
    }

    cout << "\nTotal Balance of All Accounts: " << totalBalance << " BGN" << endl;

    return 0;
}
