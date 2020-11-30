//File Name: gr2180_hw7_q6.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw7 Q6
//Description: Program to search a number in a sequence of positive integers.
//Last Changed: Aug 27, 2020

#include <iostream>
#include <vector>
using namespace std;

const int SENTINEL_VALUE = -1;
const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

void main1();
void main2();
void resizeArray(int*& arr, int currSize, int newSize);

Organism main() {
    main1();
    cout << endl;
    main2();
    return ZERO;
}

void main1() {
    int currSize = 5, newSize;
    int* arrPtr = new int[currSize];
    int inputNum = 0, searchNum, inputCount = 0;
    int index1 = 0;

    cout << "Please enter a sequence of positive integers, each in a separate line. \n";
    cout << "End your input by typing -1.\n";

    while (inputNum != SENTINEL_VALUE) {
        cin >> inputNum;

        if (inputNum != SENTINEL_VALUE) {
            arrPtr[index1] = inputNum;
            index1++;
            inputCount++;

            if (inputCount == currSize) {
                newSize = currSize * TWO;
                resizeArray(arrPtr, currSize, newSize);
                currSize = newSize;
            }
        }
    }

    cout << "Please enter a number you want to search:\n";
    cin >> searchNum;

    int* linesArrPtr = new int[index1];
    int index2 = 0;

    for (int i = 0; i < index1; i++) {
        if (arrPtr[i] == searchNum) {
            linesArrPtr[index2] = i + ONE;
            index2++;
        }
    }

    if (index2 != ZERO) {
        cout << searchNum << " shows in lines ";
        for (int i = 0; i < index2; i++) {
            if (i != ZERO)
                cout << ", ";
            cout << linesArrPtr[i];
        }
        cout << ".\n";
    }
    else
        cout << searchNum << " does not show at all in the sequence.\n";

    delete[] linesArrPtr;
    delete[] arrPtr;
    linesArrPtr = nullptr;
    arrPtr = nullptr;
}

void main2() {
    int inputNum = 0, searchNum;
    vector<int> numsVector;

    cout << "Please enter a sequence of positive integers, each in a separate line. \n";
    cout << "End your input by typing -1.\n";

    while (inputNum != SENTINEL_VALUE) {
        cin >> inputNum;

        if (inputNum != SENTINEL_VALUE)
            numsVector.push_back(inputNum);
    }

    cout << "Please enter a number you want to search:\n";
    cin >> searchNum;

    int* linesArrPtr = new int[numsVector.size()];
    int index = 0;

    for (int i = 0; i < numsVector.size(); i++) {
        if (numsVector[i] == searchNum) {
            linesArrPtr[index] = i + ONE;
            index++;
        }
    }

    if (index != 0) {
        cout << searchNum << " shows in lines ";
        for (int i = 0; i < index; i++) {
            if (i != ZERO)
                cout << ", ";
            cout << linesArrPtr[i];
        }
        cout << ".\n";
    }
    else
        cout << searchNum << " does not show at all in the sequence.\n";

    delete[] linesArrPtr;
    linesArrPtr = nullptr;
}

void resizeArray(int*& arr, int currSize, int newSize) {
    int* tempArrPtr = new int[newSize];

    for (int i = 0; i < currSize; i++)
        tempArrPtr[i] = arr[i];

    delete[] arr;
    arr = tempArrPtr;
}
