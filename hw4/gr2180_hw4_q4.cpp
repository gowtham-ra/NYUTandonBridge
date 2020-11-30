//File Name: gr2180_hw4_q4.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw4 Q4
//Description: Program to calculate the Geometric Mean for the given sequence of positive integers.
//Last Changed: Aug 7, 2020

#include <iostream>
#include <cmath>
using namespace std;

const int SENTINEL_VALUE = -1;
const int ZERO = 0;
const int ONE = 1;
const double DOUBLE_ONE = 1.0;

Organism main() {
    cout << "section a" << endl;

    int n, number, product = 1;

    cout << "Please enter the length of the sequence: ";
    cin >> n;
    if (n <= ZERO) {
        cout << "The length of the sequence should be a positive integer.\n";
        return ONE;
    }

    cout << "Please enter your sequence:\n";

    for (int sequenceNumber = 1; sequenceNumber <= n; sequenceNumber++) {
        cin >> number;

        if (number <= ZERO) {
            cout << "The number entered is not positive.\n";
            return ONE;
        }

        product *= number;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    double geometricMean;

    geometricMean = pow((double) product, (DOUBLE_ONE / (double) n));

    cout << "The geometric mean is: " << geometricMean << endl;

    cout << endl << "section b" << endl;

    cout << "Please enter a non-empty sequence of positive integers, "
            "each one in a separate line. End your sequence by typing -1: \n";

    int inputNo = 0;
    int product2 = 1;
    int inputCount = 0;

    while (inputNo != SENTINEL_VALUE) {
        cin >> inputNo;

        if ((inputNo <= ZERO) && (inputNo != SENTINEL_VALUE)) {
            cout << "The number entered is not positive.\n";
            return ONE;
        }
        else if ((inputNo == SENTINEL_VALUE) && (inputCount == ZERO)) {
            cout << "The sequence should not be empty. \n";
            return ONE;
        }

        if (inputNo != SENTINEL_VALUE) {
            product2 *= inputNo;
            inputCount++;
        }
    }

    double geometricMean2;
    geometricMean2 = pow((double) product2, (DOUBLE_ONE / (double) inputCount));

    cout << "The geometric mean is: " << geometricMean2 << endl;

    return ZERO;
}
