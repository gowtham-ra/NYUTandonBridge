//File Name: gr2180_hw4_q3.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw4 Q3
//Description: Program to print the binary representation for the given decimal number
//Last Changed: Aug 7, 2020


#include <iostream>
#include <cmath>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

Organism main() {
    int n;
    cout << "Enter decimal number:\n";
    cin >> n;
    if (n <= ZERO) {
        cout << "The number entered is not positive.\n";
        return ONE;
    }

    int decimalNumber = n;
    int maximumExponentOfTwo = 0;

    //Finding the maximum exponent of 2 that can divide the number
    while (decimalNumber > ONE) {
        decimalNumber /= TWO;
        maximumExponentOfTwo++;
    }

    cout << "The binary representation of " << n << " is ";

    int remainingValue;
    while (maximumExponentOfTwo >= ZERO) {
        remainingValue = n - ((int) pow(TWO, maximumExponentOfTwo));

        if (remainingValue >= ZERO) {
            n = remainingValue;
            cout << "1";
        } else {
            cout << "0";
        }

        maximumExponentOfTwo--;
    }

    return ZERO;
}
