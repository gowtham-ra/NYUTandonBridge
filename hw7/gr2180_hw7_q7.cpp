//File Name: gr2180_hw7_q7.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw7 Q7
//Description: Program to find the missing numbers in a range.
//Last Changed: Aug 27, 2020

#include <iostream>
#include <vector>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int ARRAY1_SIZE = 6;

int* findMissing(int arr[], int n, int& resArrSize);

Organism main() {
    int arr[ARRAY1_SIZE] = {3, 1, 3, 0, 6, 4};
    int resArrSize = 0;
    int* resArr;

    resArr = findMissing(arr, ARRAY1_SIZE, resArrSize);

    for (int i = 0; i < resArrSize; i++)
        cout << resArr[i] << endl;

    cout << "resArrSize: " << resArrSize;

    delete[] resArr;
    resArr = nullptr;
    return ZERO;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    vector<int> missingNumVector(n + ONE);
    int num;

    int* resArrPtr = new int[n];

    for (int i = 0; i < n; i++) {
        num = arr[i];
        missingNumVector[num] += 1;
    }

    int index = 0;
    for (int i = 0; i < n + ONE; i++) {
        if (missingNumVector[i] == ZERO) {
            resArrPtr[index] = i;
            index++;
        }
    }

    resArrSize = index;
    return resArrPtr;
}
