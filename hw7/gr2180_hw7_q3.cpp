//File Name: gr2180_hw7_q3.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw7 Q3
//Description: Program to reorder the elements of an array so that all odd numbers come first
//in the same order and evens will be placed after odd in a reversed order.
//Last Changed: Aug 27, 2020

#include <iostream>
#include <vector>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

void oddsKeepEvensFlip(int arr[], int arrSize);
void swap (int& num1, int& num2);
void reverseVector(vector<int> &arrVector, int vectorSize);

Organism main() {
    int arrSize = 15;
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    oddsKeepEvensFlip(arr,arrSize);

    for (auto el : arr) {
        cout << el << " ";
    }
    return ZERO;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    vector<int> oddVector;
    vector<int> evenVector;

    //Grouping the elements into odd and even vectors
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % TWO == ZERO)
            evenVector.push_back(arr[i]);
        else
            oddVector.push_back(arr[i]);
    }

    reverseVector(evenVector, evenVector.size());

    for (int i = 0; i < oddVector.size(); i++) {
        arr[i] = oddVector[i];
    }

    for (int i = oddVector.size(), j = 0; i < arrSize; i++, j++) {
        arr[i] = evenVector[j];
    }
}

void reverseVector(vector<int> &arrVector, int vectorSize) {
    for (int i = 0, j = vectorSize - ONE; i < j; i++, j--) {
        swap(arrVector[i], arrVector[j]);
    }
}

void swap (int& num1, int& num2) {
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}