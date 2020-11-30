//
// Created by Gowtham Ra on 03/09/20.
//

#include <iostream>

using namespace std;

int maxZeroLength(int nums[], int len, int startIdx);

int main() {
    int max;
    int arr[6] = {0, 0 , 1, 0, 0, 0} ;
    max = maxZeroLength(arr, 6, 0);
    cout << max;
    return 0;
}

// [0, 0, 1, 0, 0, 1]
int maxZeroLength(int nums[], int len, int startIdx) {
    if (startIdx >= len)
        return 0;
    else {
        int zeros = 0;

        while ((startIdx < len) && (nums[startIdx++] == 0)) {
            zeros++;
        }
        return max(zeros, maxZeroLength(nums, len, startIdx));
    }



}
