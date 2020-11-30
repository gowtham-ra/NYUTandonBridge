// Created by Gowtham Ra on 08/09/20.
// Program to demonstrate the class BankAccount (Display 10.5 Savitch)

#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
    double interestRate;
    double fraction(double percent);
public:
    double getBalance();

    void setBalance(int dollars, int cents, double rate);

    double getInterestRate();

    void setBalance(int dollars, double interestRate);

    void update();

    void output();
};

double BankAccount::fraction(double percent) {
    return (percent / 100.0);
}

void BankAccount::update() {
    balance = balance + (fraction(interestRate) * balance);

}

void BankAccount::output() {
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "Account balance $" << balance << endl;
    cout << "Interest rate " << interestRate << "%\n";
}

void BankAccount::setBalance(int dollars, int cents, double rate) {
    if ((dollars < 0) || (cents < 0) || (rate < 0)) {
        cout << "Illegal values given for money or interest rate\n";
        exit(1);
    }
    else {
        balance = dollars + (0.01 * cents);
        interestRate = rate;
    }
}

void BankAccount::setBalance(int dollars, double rate) {
    if ((dollars < 0) || (rate < 0)) {
        cout << "Illegal values given for money or interest rate\n";
        exit(1);
    }
    else {
        balance = dollars;
        interestRate = rate;
    }
}

double BankAccount::getBalance() {
    return balance;
}

double BankAccount::getInterestRate() {
    return interestRate;
}

int main() {
    BankAccount account1, account2;

    cout << "Start of Test:\n";
    account1.setBalance(123, 99, 3.00);
    cout << "account1 initial statement:\n";
    account1.output();

    account1.setBalance(100, 5);
    cout << "account1 with new setup:\n";
    account1.output();

    account1.update();
    cout << "account1 after update:\n";
    account1.output();

    account2 = account1;
    cout << "account2:\n";
    account2.output();

    return 0;
}


