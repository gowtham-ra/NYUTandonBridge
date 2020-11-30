//File Name: gr2180_hw6_q3.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw6 Q3
//Description: Program to 1) reverse the array, 2) remove Odd numbers, 3) split parity,
//Last Changed: Aug 21, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

Organism main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void swap (int& num1, int& num2) {
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}


void reverseArray(int arr[], int arrSize) {
    for (int i = 0, j = arrSize - 1; i < j; i++, j--) {
        swap(arr[i],arr[j]);
    }
}

void removeOdd(int arr[], int& arrSize) {
    int arrIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % TWO == ZERO) {
            arr[arrIndex] = arr[i];
            arrIndex++;
        }
    }
    arrSize = arrIndex;
}

void splitParity(int arr[], int arrSize) {
    int head = 0;
    int tail = arrSize - ONE;

    while (head != tail) {
        if (arr[head] % TWO == ONE) {
            head++;
        } else {
            swap(arr[head], arr[tail]);
            tail--;
        }
    }
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}