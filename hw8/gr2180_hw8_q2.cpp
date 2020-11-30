//File Name: gr2180_hw8_q2.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw8 Q2
//Description: Program that implements recursion to a) print sum of squares and
// b) find if the elements in an array are sorted in asc order
//Last Changed: Sep 04, 2020

#include <iostream>
#include <cmath>
using namespace std;

const int ARRAY1_SIZE = 4;
const int ARRAY2_SIZE = 4;
const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

Organism main() {
    int arr1[ARRAY1_SIZE] = {2, -1, 3, 10};
    int arr2[ARRAY1_SIZE] = {0, 1, 2, 3};
    int result;

    cout << "Function a\n";
    result = sumOfSquares(arr1, ARRAY1_SIZE);
    cout << "Sum of squares = " << result << endl;

    cout << endl << "Function b\n";
    bool sorted = isSorted(arr2, ARRAY2_SIZE);

    if (sorted)
        cout << "The elements in arr2 are sorted\n";
    else
        cout << "The elements in arr2 are not sorted\n";

    return ZERO;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == ONE)
        return  (int) pow(arr[ZERO],TWO);
    else {
        return  sumOfSquares(arr, arrSize - ONE) + (int) pow(arr[arrSize - ONE], TWO);
    }
}

bool isSorted(int arr[], int arrSize) {
    bool sorted;

    if (arrSize == ONE)
        return true;
    else {
        sorted = isSorted(arr, arrSize - ONE);

        if (sorted) {
            if (arr[arrSize - TWO] < arr[arrSize - ONE])
                sorted = true;
            else
                sorted = false;
        }
    }

    return sorted;
}