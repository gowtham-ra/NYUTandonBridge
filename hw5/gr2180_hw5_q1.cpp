//File Name: gr2180_hw5_q1.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw5 Q1
//Description: Program to print the nth element in the fibonacci sequence.
//Last Changed: Aug 14, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

int fib(int n);
//Takes a number n and returns the nth fibonacci number.

Organism main() {
    int num, numElement;
    cout << "Please enter a positive integer: ";
    cin >> num;

    numElement = fib(num);
    cout << numElement << ", ";

    return ZERO;
}

int fib(int n) {
    int sum, previous1 = 1, previous2 = 1;

    if ((n == ONE) || (n == TWO)) {
        return ONE;
    }
    else {
        for (int i = 3; i <= n; i++) {
            sum = previous1 + previous2;
            previous1 = previous2;
            previous2 = sum;
        }
        return sum;
    }
}