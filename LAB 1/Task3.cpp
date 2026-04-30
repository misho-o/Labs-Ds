#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    // 1. Default Constructor
    BankAccount() {
        balance = 0;
    }

    // 2. Parameterized Constructor
    BankAccount(double b) {
        balance = b;
    }

    // 3. Copy Constructor
    BankAccount(const BankAccount &obj) {
        balance = obj.balance;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance!\n";
    }

    // Getter
    double getBalance() {
        return balance;
    }
};

int main() {

    // 1. Default Constructor
    BankAccount account1;
    cout << "Account1 Balance (Default): $" 
         << account1.getBalance() << endl;

    // 2. Parameterized Constructor
    BankAccount account2(1000);
    cout << "Account2 Balance (Parameterized): $" 
         << account2.getBalance() << endl;

    // 3. Copy Constructor
    BankAccount account3 = account2;

    // Deduct $200 from account3
    account3.withdraw(200);

    cout << "Account3 Balance after withdrawal: $" 
         << account3.getBalance() << endl;

    // Ensure account2 is unchanged
    cout << "Account2 Balance (unchanged): $" 
         << account2.getBalance() << endl;

    return 0;
}