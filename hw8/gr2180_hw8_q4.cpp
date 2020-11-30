//File Name: gr2180_hw8_q4.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw8 Q4
//Description: Program that uses recursion to implement jump board game.
//Last Changed: Sep 04, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

int lowestCostInJumpIt(int arr[], int arrSize);

int main() {
    int arr[] = {0, 3, 60, 6, 57, 58};
    int arrSize = 6;
    int lowestCost;

    lowestCost = lowestCostInJumpIt(arr, arrSize);
    cout << "Lowest total cost = " << lowestCost << endl;
    return ZERO;
}

int lowestCostInJumpIt(int arr[], int arrSize) {
    int sum;
    int adjColumn;
    int jumpColumn;

    if (arrSize == ONE)
        return arr[ZERO];

    else if (arrSize == TWO)
        return arr[ZERO] + arr[ONE];

    else {
        adjColumn = *(arr + ONE);
        jumpColumn = *(arr + TWO);

        if (adjColumn >= jumpColumn) {
            sum = lowestCostInJumpIt(arr + TWO, arrSize - TWO);
            sum += *arr;
        }
        else {
            sum = lowestCostInJumpIt(arr + ONE, arrSize - ONE);
            sum += *arr;
        }
    }
    return sum;
}
