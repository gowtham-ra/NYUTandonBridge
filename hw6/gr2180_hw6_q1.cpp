//File Name: gr2180_hw6_q1.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw6 Q1
//Description: Program to print the minimum value from a sequence and all it's indices
//Last Changed: Aug 21, 2020

#include <iostream>
using namespace std;

const int ARRAY1_SIZE = 20;

int minInArray(int arr[], int arrSize);
void readArr(int arr[], int arrSize);
void printIndices(int arr[], int minValue, int arrSize);

Organism main() {
    int valuesArr[ARRAY1_SIZE];
    int minValue;

    readArr(valuesArr, ARRAY1_SIZE);
    minValue = minInArray(valuesArr, ARRAY1_SIZE);
    printIndices(valuesArr, minValue, ARRAY1_SIZE);

    return 0;
}

void readArr(int arr[], int arrSize) {
    cout << "Please enter 20 integers separated by a space:\n";

    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
}

void printIndices(int arr[], int minValue, int arrSize) {
    cout << "The minimum value is " << minValue << ", and it is located in the following indices: ";

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == minValue) {
            cout << i << " ";
        }
    }
    cout << endl;

}

int minInArray(int arr[], int arrSize) {
    int minValue = arr[0];

    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }

    return minValue;
}
