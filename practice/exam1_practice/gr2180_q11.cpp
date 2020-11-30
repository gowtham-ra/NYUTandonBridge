
#include <iostream>
#include <string>
using namespace std;

void moveZeroes(int nums[], int arrSize); // ARR SIZE NOT GIVEN? HOW TO FIND SIZE?
void swap(int& a, int& b);

int main() {
    int arr[] = {0, 2, 0, 1, 0};
    int arrSize = 5;

    moveZeroes(arr, arrSize);

    for (auto el : arr)
        cout << el << " ";

    return 0;
}

void moveZeroes(int nums[], int arrSize) {
    int head = 0;
    int curIndex = 0;

    while (curIndex < arrSize) {
        if (nums[curIndex] != 0) {
            swap(nums[curIndex], nums[head]);
            head++;
        }
        curIndex++;
    }
}

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}