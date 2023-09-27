#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(const string& accNum, const string& accName, double initialBalance)
        : accountNumber(accNum), accountHolderName(accName), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance.\n";
        }
    }

    void checkBalance() {
        cout << "Account Information:\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder Name: " << accountHolderName << "\n";
        cout << "Balance: $" << balance << "\n";
    }
};

int main() {
    string accountNumber, accountHolderName;
    double initialBalance;

    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Account Holder Name: ";
    cin.ignore(); // Clear newline character from buffer
    getline(cin, accountHolderName);
    cout << "Enter Initial Balance: $";
    cin >> initialBalance;

    BankAccount account(accountNumber, accountHolderName, initialBalance);

    int choice;
    double amount;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the amount to deposit: $";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter the amount to withdraw: $";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
