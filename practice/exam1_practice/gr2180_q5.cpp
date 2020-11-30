// Name: Gowtham Ra
// ID: gr2180
//

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Please enter a positive integer: ";
    cin >> n;

    int number = n;
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    cout << sum;

    return 0;
}

