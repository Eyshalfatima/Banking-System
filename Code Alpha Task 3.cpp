#include <iostream>
#include <vector>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void showTransaction() {
        cout << type << " : Rs." << amount << endl;
    }
};

class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> history;

public:
    Account(int accNo, double bal = 0) {
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));

        cout << "Deposit Successful!\n";
    }

    void withdraw(double amount) {

        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        }
        else {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));

            cout << "Withdrawal Successful!\n";
        }
    }

    void transfer(Account& receiver, double amount) {

        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        }
        else {
            balance -= amount;
            receiver.balance += amount;

            history.push_back(Transaction("Transfer Sent", amount));
            receiver.history.push_back(Transaction("Transfer Received", amount));

            cout << "Transfer Successful!\n";
        }
    }

    void showBalance() {
        cout << "Current Balance: Rs." << balance << endl;
    }

    void showHistory() {

        cout << "\nTransaction History:\n";

        for (int i = 0; i < history.size(); i++) {
            history[i].showTransaction();
        }
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

class Customer {
private:
    string name;
    Account account;

public:
    Customer(string n, int accNo, double bal)
        : account(accNo, bal) {

        name = n;
    }

    void showCustomer() {

        cout << "\nCustomer Name: " << name << endl;

        cout << "Account Number: "
            << account.getAccountNumber() << endl;

        account.showBalance();
    }

    Account& getAccount() {
        return account;
    }
};

int main() {

    Customer c1("Ali", 101, 5000);
    Customer c2("Ahmed", 102, 3000);

    int choice;
    double amount;

    do {

        cout << "\n===== BANK MENU =====\n";

        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Show Balance\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter Amount: ";
            cin >> amount;

            c1.getAccount().deposit(amount);
            break;

        case 2:

            cout << "Enter Amount: ";
            cin >> amount;

            c1.getAccount().withdraw(amount);
            break;

        case 3:

            cout << "Enter Amount: ";
            cin >> amount;

            c1.getAccount().transfer(c2.getAccount(), amount);
            break;

        case 4:

            c1.showCustomer();
            break;

        case 5:

            c1.getAccount().showHistory();
            break;

        case 6:

            cout << "Thank You!\n";
            break;

        default:

            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}