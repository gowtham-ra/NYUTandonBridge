// Created by Gowtham Ra on 26/09/20.
// Program to implement sort algorithms

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ARR_SIZE = 10;

void swap(int& value1, int& value2);
void selectionSort(int arr[], int arrSize);
int findMinIndex(const int arr[], int size);
void bubbleSort(int arr[], int arrSize);
void insertionSort(int arr[], int arrSize);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int leftLow, int leftHigh, int rightHigh);
void quickSort1(int arr[], int start, int end);
int randomPivotPartition(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void quickSort2(int arr[], int start, int end);
void insertionSort(int arr[], int start, int end);

int main() {
    srand(time(NULL));
    int arr1[ARR_SIZE] = {8, 9, 4, 5, 3, 7, 2, 1, 6, 3};

//    selectionSort(arr1,ARR_SIZE);
//    bubbleSort(arr1, ARR_SIZE);
//    insertionSort(arr1, ARR_SIZE);
//    mergeSort(arr1, 0, ARR_SIZE - 1); //DIFFICULT DO AGAIN
//    quickSort1(arr1, 0, ARR_SIZE - 1);
    quickSort2(arr1, 0, ARR_SIZE - 1);

    for(auto el : arr1)
        cout << el << ", ";

    return 0;
}

int findMinIndex(const int arr[], int arrSize) {
    int minVal = arr[0];
    int minIdx = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void swap(int& value1, int& value2) {
    int temp;
    temp = value1;
    value1 = value2;
    value2 = temp;
}

void selectionSort(int arr[], int arrSize) {
    int minIdx;
    for (int i = 0; i < arrSize; i++) { //(N)
        minIdx = findMinIndex(arr + i, arrSize - i) + i; //(N)
        swap(arr[i], arr[minIdx]);
    }
}

void bubbleSort(int arr[], int arrSize) {
    //size-1 in the range because last iteration will have everything sorted.
    for (int i = 0; i < arrSize - 1; i++) { //(N)
        //-i in the range because the biggest item is moved to the end in every iteration
        for (int j = 0; j < arrSize - 1 - i; j++) { //(N)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void insertionSort(int arr[], int arrSize) {
    int j;
    for (int i = 1; i < arrSize; i++) { //(N)
        j = i;
        while ((j > 0) && (arr[j] < arr[j-1])) { //(N)
            swap(arr[j-1], arr[j]); //{8, 9, 4, 5, 3, 7, 2, 1, 6, 3};
            j--;
        }
    }
}

void mergeSort(int arr[], int low, int high) {
    int mid;
    if (low == high)
        return;
    else {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid); //(log N)
        mergeSort(arr, mid + 1, high); //(log N)
        merge(arr, low, mid, high); //(N)
    }
}

void merge(int arr[], int leftLow, int leftHigh, int rightHigh) {
    int size = rightHigh - leftLow + 1;
    int* tempArr = new int[size];
    int left = leftLow;
    int right = leftHigh + 1;
    int idx = 0;

    while ((left <= leftHigh) && (right <= rightHigh)) {
        if (arr[left] < arr[right])
            tempArr[idx++] = arr[left++];
        else
            tempArr[idx++] = arr[right++];
    }

    while (left <= leftHigh)
        tempArr[idx++] = arr[left++];

    while (right <= rightHigh)
        tempArr[idx++] = arr[right++];

    for (int i = 0, arrIdx = leftLow; i < size; i++, arrIdx++)
        arr[arrIdx] = tempArr[i];

    delete [] tempArr;
}

//Implementation method 1 given in CLRS and online resources
void quickSort1(int arr[], int start, int end) {
    int pIdx;
    if (start < end) {
        pIdx = randomPivotPartition(arr, start, end);
        quickSort1(arr, start, pIdx - 1);
        quickSort1(arr, pIdx + 1, end);
    }
}

//Choosing a random element as pivot and sending it for partition
int randomPivotPartition(int arr[], int start, int end) {
    int pivotIdx, randomNum;
    randomNum = rand();

    //Choose a random pivot value within the given range
    pivotIdx = start + (randomNum % (end - start + 1));

    //Move pivot to the end
    swap(arr[pivotIdx], arr[end]);
    return partition(arr, start, end);
}

//Partitioning the array with end as the pivot
int partition(int arr[], int start, int end) {
    int pivot, swapIdx;
    pivot = end;
    swapIdx = start;

    //Iterate the list to have values lesser than pivot before swapIdx
    for (int i = start; i < end; i++) {
        if (arr[i] < arr[pivot]) {
            swap(arr[i], arr[swapIdx]);
            swapIdx++;
        }
    }
    //Move pivot to swapIdx so that all lower values to pivot are to its left
    swap(arr[swapIdx], arr[pivot]);
    return swapIdx;
}

//Implementation method 2 given in DSA book and NYU bridge - CHECK AGAIN NOT WORKING
void quickSort2(int arr[], int start, int end) {
    if (start + 10 > end) {
        insertionSort(arr, start, end);
    }
    int center = (start + end) / 2;

    //Median-of-three partitioning
    if (arr[center] < arr[start])
        swap(arr[center], arr[start]);
    if (arr[end] < arr[start])
        swap(arr[end], arr[start]);
    if (arr[end] < arr[center])
        swap(arr[end], arr[center]);

    int pivot = arr[center];
    //Moving the pivot to the last
    swap(arr[center], arr[end - 1]);
    int i = start;
    int j = end - 1;

    for(;;) {
        while (arr[++i] < pivot) {}
        while (pivot < arr[--j]) {}
        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }
    swap(arr[i], arr[end - 1]);

    quickSort2(arr, start, i - 1);
    quickSort2(arr, i + 1, end);
}

//Insertion sort algorithm for quicksort
void insertionSort(int arr[], int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int value = arr[i];
        int j;
        for (j = i - 1; j > start && arr[j-1] > value; j--)
            swap(arr[j-1], arr[j]);
    }
}