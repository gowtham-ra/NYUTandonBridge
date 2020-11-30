//File Name: gr2180_hw8_q3.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw8 Q3
//Description: Program that implements recursion to 1) find the min value from all the elements
// in an array and 2) find the min value within the given positions in the array
//Last Changed: Sep 04, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

Organism main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout << res1 << " " << res2 << endl; //should both be -9

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4);
    cout << res3 << " " << res4 << endl; //should both be 3

    return ZERO;
}

int minInArray1(int arr[], int arrSize) {
    int min;
    if (arrSize == ONE)
        return arr[ZERO];
    else {
        min = minInArray1(arr, arrSize - ONE);
        if (arr[arrSize - ONE] < min)
            min = arr[arrSize - ONE];
    }
    return min;
}

int minInArray2(int arr[], int low, int high) {
    int min;
    if (low == high)
        return arr[low];
    else {
        min = minInArray2(arr, low, high - ONE);
        if (arr[high] < min)
            min = arr[high];
    }
    return min;
}