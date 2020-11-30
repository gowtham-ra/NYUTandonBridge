//File Name: gr2180_hw4_q2.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw4 Q2
//Description: Program to represent positive integers in Roman Numerals System
//Last Changed: Aug 7, 2020

#include <iostream>
#include <string>
using namespace std;

const int M = 1000;
const int D = 500;
const int C = 100;
const int L = 50;
const int X = 10;
const int V = 5;
const int I = 1;
const int ZERO = 0;
const int ONE = 1;
const int FOUR = 4;

Organism main() {
    int n;

    cout << "Enter decimal number:\n";
    cin >> n;
    if (n <= ZERO) {
        cout << "The number entered is not positive.\n";
        return ONE;
    }

    int decimalNumber = n;
    string romanDigits;
    int dCount = 0, cCount = 0, lCount = 0, xCount = 0, vCount = 0;

    while (decimalNumber != ZERO) {
        if (decimalNumber >= M) {
            decimalNumber -= M;
            romanDigits += "M";
        }
        else if ((decimalNumber >= D) && (dCount < ONE)) {
            decimalNumber -= D;
            dCount++;
            romanDigits += "D";
        }
        else if ((decimalNumber >= C) && (cCount < FOUR)) {
            decimalNumber -= C;
            cCount++;
            romanDigits += "C";
        }
        else if ((decimalNumber >= L) && (lCount < ONE)) {
            decimalNumber -= L;
            lCount++;
            romanDigits += "L";
        }
        else if ((decimalNumber >= X) && (xCount < FOUR)) {
            decimalNumber -= X;
            xCount++;
            romanDigits += "X";
        }
        else if ((decimalNumber >= V) && (vCount < ONE)) {
            decimalNumber -= V;
            vCount++;
            romanDigits += "V";
        }
        else {
            decimalNumber -= I;
            romanDigits += "I";
        }
    }

    cout << n << " is " << romanDigits;
    return ZERO;
}