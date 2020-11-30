//File Name: gr2180_hw7_q5.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw7 Q5
//Description: Program to get the positive numbers from an array using 4 different implementations.
//Last Changed: Aug 26, 2020

#include <iostream>
using namespace std;

const int ARRAY1_SIZE = 6;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);


int main() {
    int* posArr1, posArrSize1;
    int* posArr2, posArrSize2;
    int* posArr3, posArrSize3;
    int* posArr4, posArrSize4;
    int arr1[ARRAY1_SIZE] = {-1, 0, 1, 2, 3, 4};
    int arr2[ARRAY1_SIZE] = {-2, -1, 0, 1, 2, 3};
    int arr3[ARRAY1_SIZE] = {-3, -2, -1, 0, 1, 2};
    int arr4[ARRAY1_SIZE] = {-4, -3, -2, -1, 0, 1};

    cout << "Function 1" << endl;
    posArr1 = getPosNums1(arr1, ARRAY1_SIZE, posArrSize1);
    for (int i = 0; i < posArrSize1; i++) {
        cout << posArr1[i] << " ";
    }
    cout << endl << "outPosArrSize: " << posArrSize1 << endl;

    cout << endl << "Function 2" << endl;
    getPosNums2(arr2, ARRAY1_SIZE, posArr2, posArrSize2);
    for (int i = 0; i < posArrSize2; i++) {
        cout << posArr2[i] << " ";
    }
    cout << endl << "outPosArrSize: " << posArrSize2 << endl;

    cout << endl << "Function 3" << endl;
    posArr3 = getPosNums3(arr3, ARRAY1_SIZE, &posArrSize3);
    for (int i = 0; i < posArrSize3; i++) {
        cout << posArr3[i] << " ";
    }
    cout << endl << "outPosArrSize: " <<  posArrSize3 << endl;

    cout << endl << "Function 4" << endl;
    getPosNums4(arr4, ARRAY1_SIZE, &posArr4, &posArrSize4);
    for (int i = 0; i < posArrSize4; i++) {
        cout <<  posArr4[i] << " ";
    }
    cout << endl << "outPosArrSize: " << posArrSize4 << endl;

    delete [] posArr1;
    posArr1 = nullptr;
    delete [] posArr2;
    posArr2 = nullptr;
    delete [] posArr3;
    posArr3 = nullptr;
    delete [] posArr4;
    posArr4 = nullptr;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int num;
    int* posArrPtr = new int[arrSize];
    int posArrIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        num = arr[i];
        if (num > 0) {
            posArrPtr[posArrIndex] = num;
            posArrIndex++;
        }
    }
    outPosArrSize = posArrIndex;
    return posArrPtr;
}

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int num;
    int* posArrPtr = new int[arrSize];
    int posArrIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        num = arr[i];
        if (num > 0) {
            posArrPtr[posArrIndex] = num;
            posArrIndex++;
        }
    }
    outPosArr = posArrPtr;
    outPosArrSize = posArrIndex;
}

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr) {
    int num;
    int* posArrPtr = new int[arrSize];
    int posArrIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        num = arr[i];
        if (num > 0) {
            posArrPtr[posArrIndex] = num;
            posArrIndex++;
        }
    }
    *outPosArrSizePtr = posArrIndex;
    return posArrPtr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int num;
    int* posArrPtr = new int[arrSize];
    int posArrIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        num = arr[i];
        if (num > 0) {
            posArrPtr[posArrIndex] = num;
            posArrIndex++;
        }
    }
    *outPosArrPtr = posArrPtr;
    *outPosArrSizePtr = posArrIndex;
}

