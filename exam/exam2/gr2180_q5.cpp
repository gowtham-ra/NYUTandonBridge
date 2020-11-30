//Gowtham Rajeshshekaran
//gr2180

#include <iostream>
using namespace std;

double findMedian(int arr[], int n);

int main() {
    int arr[] = {3, 5, 3, 7, 1, 7, 6};

    double median = findMedian(arr, 7);

    cout << median;
    return 0;
}

double findMedian(int arr[], int n) {
    int middleNumber;
    double median = 0;
    int size = n + 1;

    middleNumber = (n / 2) + 1;

    int* countArrPtr = new int[size];

    for (int i = 0; i <= n; i++) {
        countArrPtr[i] = 0;
    }

    int value;
    for (int i = 0 ; i < n; i++) {
        value = arr[i];
        countArrPtr[value] = countArrPtr[value] + 1;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += countArrPtr[i];

        if (count >= middleNumber) {
            median = i;
            break;
        }
    }

    delete [] countArrPtr;
    countArrPtr = nullptr;

    return median;
}