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
class BankingSystem {
public:
    vector<Account> accounts;

    void createAccount() {
        string accNo, name;
        double initialDeposit;

        cout << "Enter Account Number: ";
        cin >> accNo;
        cin.ignore();  // Clear the newline character left by previous input
        cout << "Enter Account Holder Name: ";
        getline(cin, name);
        cout << "Enter Initial Deposit Amount: ";
        cin >> initialDeposit;

        Account newAccount(accNo, name, initialDeposit);
        accounts.push_back(newAccount);
        cout << "Account created successfully!" << endl;
    }

    Account* findAccount(const string& accountNumber) {
        // Traditional for loop to iterate through accounts
        for (int i = 0; i < accounts.size(); i++) {
            Account& account = accounts[i];
            if (account.accountNumber == accountNumber) {
                return &account;
            }
        }
        // Return NULL instead of nullptr for older C++ versions
        return NULL;
    }

    void deposit() {
        string accountNumber;
        double amount;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        Account* account = findAccount(accountNumber);
        if (account != NULL) {
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            account->deposit(amount);
            cout << "Deposit Successful!" << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdraw() {
        string accountNumber;
        double amount;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        Account* account = findAccount(accountNumber);
        if (account != NULL) {
            cout << "Enter Withdraw Amount: ";
            cin >> amount;
            account->withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void viewBalance() {
        string accountNumber;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        Account* account = findAccount(accountNumber);
        if (account != NULL) {
            account->viewBalance();
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void viewTransactionHistory() {
        string accountNumber;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        Account* account = findAccount(accountNumber);
        if (account != NULL) {
            account->viewTransactionHistory();
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void run() {
        int choice;

        while (true) {
            cout << "\n******** Banking System ********" << endl;
            cout << "1. Create Account" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. View Balance" << endl;
            cout << "5. View Transaction History" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    createAccount();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    viewBalance();
                    break;
                case 5:
                    viewTransactionHistory();
                    break;
                case 6:
                    cout << "Exiting the banking system..." << endl;
                    return;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
};

int main() {
    BankingSystem bankingSystem;
    bankingSystem.run();
    return 0;
}
