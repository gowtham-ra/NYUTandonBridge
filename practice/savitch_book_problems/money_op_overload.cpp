// Created by Gowtham Ra on 14/09/20.
// Program to demonstrate operators overloading using class Money.
// Pending: Overload other remaining operators.

#include <iostream>
#include <cstdlib>
using namespace std;

class Money {
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount); //Overloading minus indication operator
    friend bool operator ==(const Money& amount1, const Money& amount2);

    //stream is passed as param to specify which stream are we operating on
    friend istream& operator >>(istream& ins, Money& amount);
    friend ostream& operator <<(ostream& outs, const Money& amount);

    Money(int dollars, int cents);
    Money(int dollars);
    Money();

    double getValue() const;

private:
    int totalCents;
};

int digitToInt(char c);

int main() {
    Money amount;
    cout << "Please enter the amount in the form ($decimal.cents): ";
    cin >> amount;
    cout << "The amount you have is\n";
    cout << amount;
    return 0;
}

Money operator+(const Money &amount1, const Money &amount2) {
    Money tempAmount;
    tempAmount.totalCents = amount1.totalCents + amount2.totalCents;
    return tempAmount;
}

Money operator-(const Money &amount1, const Money &amount2) {
    Money tempAmount;
    tempAmount.totalCents = amount1.totalCents - amount2.totalCents;
    return tempAmount;
}

Money operator-(const Money &amount) {
    Money tempAmount;
    tempAmount.totalCents = - amount.totalCents;
    return tempAmount;
}

bool operator==(const Money &amount1, const Money &amount2) {
    return (amount1.totalCents == amount2.totalCents);
}

Money::Money(int dollars, int cents) {
    this->totalCents = (dollars * 100) + cents;
}

Money::Money(int dollars) : totalCents(dollars * 100) {}

Money::Money() : totalCents(0) {}

double Money::getValue() const {
    return totalCents;
}

istream &operator>>(istream &ins, Money &amount) {
    char oneChar, decimalPoint, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> oneChar;

    if (oneChar == '-') {
        negative = true;
        ins >> oneChar;
    } else
        negative = false;

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if ((oneChar != '$') || (decimalPoint != '.') || (!(isdigit(digit1))) || (!(isdigit(digit2)))) {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = (digitToInt(digit1) * 10) + digitToInt(digit2);
    amount.totalCents = dollars * 100 + cents;

    if (negative)
        amount.totalCents = - amount.totalCents;
    return ins;
}

ostream &operator<<(ostream &outs, const Money &amount) {
    long positiveCents, dollars, cents;
    positiveCents = labs(amount.totalCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;

    if (amount.totalCents < 0)
        outs << "- $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';

    outs << cents;
    return outs;
}

int digitToInt(char c) {
    int digit;
    digit = c - '0';
    return digit;
}

