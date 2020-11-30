//File Name: gr2180_hw5_q6.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw5 Q6
//Description: Program to print the euler's number approximated to the given number of terms.
//Last Changed: Aug 14, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

double eApprox(int n);
//Calculates the euler's number with approximation upto given number of terms.

Organism main() {
    cout.precision(30);

    int n;
    double eulersNumber;

    cout << "Please enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "The entered number is not positive";
    }

    eulersNumber = eApprox(n);
    cout << eulersNumber;

    return ZERO;
}

double eApprox(int n) {

    double exponent = ZERO;
    int factorial = ONE;

    for (int termNum = ZERO; termNum <= n; termNum++) {
        if (termNum != ZERO) {
            factorial = factorial * termNum;
        }
        exponent += (double) ONE / factorial;
    }
    return exponent;
}

