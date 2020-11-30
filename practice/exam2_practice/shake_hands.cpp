//
// Created by Gowtham Ra on 03/09/20.
//

#include <iostream>
using namespace std;

int shakeHands(int n) {
    int sum = 0;

    if (n == 1) {
        return 0;
    }
    else {
        sum += shakeHands(n - 1);

        for (int i = 1; i < n; i++)
            sum++;
    }
    return sum;
}

int main() {
    int sum = shakeHands(10);
    cout << sum;
}