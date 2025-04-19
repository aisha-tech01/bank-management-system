#include <iostream>
#include <vector>
#include <string>
#include <sstream>  // Include this for stringstream

using namespace std;

class Account {
public:
    string accountNumber;
    string holderName;
    double balance;
    vector<string> transactionHistory;

    // Constructor to initialize an account
    Account(string accNo, string name, double initialBalance) {
        accountNumber = accNo;
        holderName = name;
        balance = initialBalance;
    }

    // Function to convert a double to a string
    string doubleToString(double value) {
        stringstream ss;
        ss << value;
        return ss.str();
    }

    // Deposit function
    void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back("Deposited: " + doubleToString(amount));
    }

    // Withdraw function
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactionHistory.push_back("Withdrew: " + doubleToString(amount));
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    // Function to view transaction history
    void viewTransactionHistory() {
        cout << "Transaction History for " << holderName << " (Account Number: " << accountNumber << "):" << endl;
        
        // Using a traditional for loop to avoid C++11 issue
        for (int i = 0; i < transactionHistory.size(); i++) {
            cout << transactionHistory[i] << endl;
        }
    }

    // Function to view balance
    void viewBalance() {
        cout << "Current Balance for " << holderName << ": " << balance << endl;
    }
};
