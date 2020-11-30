//File Name: gr2180_hw4_q5.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw4 Q5
//Description: Program to print a textual image of an hourglass made of 2n lines with asterisks.
//Last Changed: Aug 7, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

Organism main() {
    int n;

    cout << "Please enter a positive integer:\n";
    cin >> n;
    if (n <= ZERO) {
        cout << "The number entered is not positive.\n";
        return ONE;
    }

    int numberOfLines = TWO * n;

    int totalCharactersInEachLine = (TWO * n) - ONE;
    int starCount = totalCharactersInEachLine;
    int spaceCount = totalCharactersInEachLine - starCount;
    bool upperHourGlass = true;
    int starIteration = 0;

    for (int lineNumber = 1; lineNumber <= numberOfLines; lineNumber++) {
        for (int space = 1; space <= spaceCount; space++) {
            cout << " ";
        }

        for (int star = 1; star <= starCount; star++) {
            cout << "*";
        }

        cout << endl;

        if ((upperHourGlass) && (starCount != ONE)) {
            spaceCount += ONE;
            starCount -= TWO;
        }
        else if ((starCount == ONE) && (starIteration == ZERO)) {
            starIteration++;
            upperHourGlass = false;
        }
        else {
            spaceCount -= ONE;
            starCount += TWO;
        }
    }

    return 0;
}