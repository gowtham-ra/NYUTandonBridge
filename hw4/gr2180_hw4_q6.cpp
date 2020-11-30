//File Name: gr2180_hw4_q6.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw4 Q6
//Description: Program to print numbers with more even digits upto n
//Last Changed: Aug 7, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;
const int TEN = 10;

Organism main() {
    int n;

    cout << "Please enter a positive integer: ";
    cin >> n;
    if (n <= ZERO) {
        cout << "The number entered is not positive.\n";
        return ONE;
    }
    else if (n == ONE) {
        cout << "No such number exists in the given range. \n";
    }

    int number = 1;
    int tempNum;
    int digit, evenCount, oddCount;
    while (number <= n) {
        tempNum = number;

        while (tempNum > ZERO) {
            digit = tempNum % TEN;
            if (digit % TWO == ZERO) {
                evenCount++;
            }
            else {
                oddCount++;
            }
            tempNum /= TEN;
        }

        if (evenCount > oddCount) {
            cout << number << endl;
        }

        evenCount = 0;
        oddCount = 0;
        number++;
    }
    return ZERO;
}