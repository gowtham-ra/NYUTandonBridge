//
// Created by Gowtham Ra on 03/09/20.
//

#include <iostream>
using namespace std;

int chocolates (int dollars) {
    int chocs;
    int coupons = 0;
    int n = 20;
    int extras = 0;

    if (dollars == 1) {
        return 1;
    }
    else {
        chocs = chocolates(dollars - 1);
        coupons++;
        chocs++;

        if (dollars == n) {
            extras = coupons / 7;
            coupons = (coupons / 7) + (coupons % 7);
            chocs += extras;
        }

    }

    return chocs;

}

int main() {
    int sum = chocolates(10);
    cout << sum;
}