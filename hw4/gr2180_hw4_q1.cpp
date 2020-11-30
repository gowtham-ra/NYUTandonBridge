//File Name: gr2180_hw4_q1.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw4 Q1
//Description: Program to print first n even numbers.
//Last Changed: Aug 7, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

Organism main() {
    int n;
    int number = 1, count = 1;

    cout << "section a" << endl;
    cout << "Please enter a positive integer: ";
    cin >> n;
    if (n <= ZERO) {
        cout << "The number entered is not positive.\n";
        return ONE;
    }

    while (count <= n) {
        if (number % TWO == ZERO) {
            cout << number << endl;
            count++;
        }
        number++;
    }

    cout << "section b" << endl;

    int input, num = 1;

    cout << "Please enter a positive integer: ";
    cin >> input;
    if (input <= ZERO) {
        cout << "The number entered is not positive.\n";
        return ONE;
    }

    for (int forCount = 1; forCount <= input; num++) {
        if (num % TWO == ZERO) {
            cout << num << endl;
            forCount++;
        }
    }

    return ZERO;
}