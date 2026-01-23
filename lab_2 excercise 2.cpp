#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
    int transactions;
    double interestRate;

public:
    // Constructor
    BankAccount() {
        balance = 0.0;
        transactions = 0;
        interestRate = 0.05; // 5% interest
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions++;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            transactions++;
        } else {
            cout << "Insufficient balance\n";
        }
    }

    void displayBalance() {
        cout << "Account Balance: " << balance << endl;
    }

    void displayTransactions() {
        cout << "Number of Transactions: " << transactions << endl;
    }

    void displayInterest() {
        cout << "Interest Earned: " << balance * interestRate << endl;
    }
};

int main() {
    BankAccount acc;
    int choice;
    double amount;

    do {
        cout << "\nMenu\n";
        cout << "1. Display balance\n";
        cout << "2. Display transactions\n";
        cout << "3. Display interest\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            acc.displayBalance();
            break;
        case 2:
            acc.displayTransactions();
            break;
        case 3:
            acc.displayInterest();
            break;
        case 4:
            cout << "Enter deposit amount: ";
            cin >> amount;
            acc.deposit(amount);
            break;
        case 5:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            acc.withdraw(amount);
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

