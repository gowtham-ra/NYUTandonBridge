//File Name: gr2180_hw4_q7.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw4 Q7
//Description: Program to display a nxn multiplication table
//Last Changed: Aug 7, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;

Organism main() {

    int n;
    cout << "Please enter a positive integer:\n";
    cin >> n;
    if (n <= ZERO) {
        cout << "The number entered is not positive.\n";
        return ONE;
    }

    for (int rowNumber = 1; rowNumber <= n; rowNumber++) {
        for (int columnNumber = 1; columnNumber <= n; columnNumber++) {
            cout << rowNumber * columnNumber << "\t";
        }
        cout << "\n";
    }

    return 0;
}