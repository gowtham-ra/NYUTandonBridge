// Created by Gowtham Ra on 25/09/20.
// Program to implement search algorithms

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int ARR_SIZE = 10;

int linearSearch(int arr[], int arrSize, int value);
int binarySearch(int arr[], int arrSize, int value);
int recLinearSearch(int arr[], int left, int right, int value);
int recBinarySearch(int arr[], int low, int high, int value);

int main() {
    int arr1[ARR_SIZE] = {3, 9, 4, 5, 3, 9, 2, 1, 6, 3};
    int arr2[ARR_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "LS index = " << linearSearch(arr1, ARR_SIZE, 50) << endl;
    cout << "BS index = " << binarySearch(arr2, ARR_SIZE, 5) << endl;
    cout << "RLS index = " << recLinearSearch(arr1, 0,ARR_SIZE - 1, 50) << endl;
    cout << "RBS index = " << recBinarySearch(arr2, 0,ARR_SIZE - 1, 9) << endl;

    return 0;
}

int linearSearch(int arr[], int arrSize, int value) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int arrSize, int value) {
    int low = 0, high = arrSize - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == value)
            return mid;
        else if (value < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int recLinearSearch(int arr[], int left, int right, int value) {
    if (left > right)
        return -1;
    else if (arr[left] == value)
        return left;
    else if (arr[right] == value)
        return right;
    return recLinearSearch(arr, left + 1, right - 1, value);
}

int recBinarySearch(int arr[], int low, int high, int value) {
    int mid;
    mid = (low + high) / 2;

    if (low > high)
        return - 1;
    else if (arr[mid] == value)
        return mid;
    else if (value < arr[mid])
        return recBinarySearch(arr, low, mid - 1, value);
    else
        return recBinarySearch(arr, mid + 1, high, value);
}

