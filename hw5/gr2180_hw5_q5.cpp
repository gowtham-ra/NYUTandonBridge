//File Name: gr2180_hw5_q5.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw5 Q5
//Description: Program to print all the perfect and amicable numbers within the given range
//Last Changed: Aug 14, 2020

#include <iostream>
#include <cmath>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
//Takes a number "num" and updates two output
//parameters with the number of num's proper divisors and their sum.

bool isPerfect(int num);
//Checks if the given number is a perfect number

Organism main() {
    int inputNum;

    cout << "Please enter a positive integer >= 2: ";
    cin >> inputNum;
    if (inputNum < TWO) {
        cout << "The number should be greater than 2\n";
        return ONE;
    }

    cout << "Perfect numbers between 2 and " << inputNum << endl;

    for (int num = 2; num <= inputNum; num++) {
        if (isPerfect(num)){
            cout << num << endl;
        }
    }

    cout << endl << "Pairs of amicable numbers between 2 and " << inputNum << endl;

    for (int num = 2; num <= inputNum; num++) {
        int countDivsN = 0, sumDivsN = 0;
        int m, countDivsM = 0, sumDivsM = 0;

        analyzeDividors(num, countDivsN, sumDivsN);
        m = sumDivsN;
        analyzeDividors(m, countDivsM, sumDivsM);

        if ((sumDivsM == num) && (num != m) && (m <= inputNum)) {
            cout << "(" << num << "," << m << ")\n";
        }
    }

    return ZERO;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    for(int n = 1; n < sqrt(num); n++ ) {
        if(num % n == ZERO){
            outCountDivs++;
            outSumDivs += n;
        }
    }

    for(int n = sqrt(num); n > ONE; n--) {
        if(num % n == ZERO) {
            if((num / n) != num) {
                outCountDivs++;
                outSumDivs += num / n;
            }
        }
    }
}

bool isPerfect(int num) {
    int countDivs = 0, sumDivs = 0;
    analyzeDividors(num, countDivs, sumDivs);
    if (sumDivs == num) {
        return true;
    }
    else
        return false;
}


