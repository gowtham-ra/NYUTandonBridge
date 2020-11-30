//Gowtham Rajeshshekaran
//gr2180

#include <iostream>
using namespace std;

const int SENTINEL_VALUE = -1;
const int ZERO = 0;
const int TWO = 2;
const int TEN = 10;

int main() {

    cout << "Please enter a sequence of positive integers, each one in a separate line.\n"
            "End your sequence by typing -1:\n";

    bool continueIteration = true;
    int evenCount = 0, oddCount = 0, totalEvenNumbers = 0;
    int inputNo, num, digit;

    while (continueIteration) {
        cin >> inputNo;

        if (inputNo == SENTINEL_VALUE) {
            continueIteration = false;
        }
        else {
            num = inputNo;
            while (num > ZERO) {
                digit = num % TEN;

                if (digit % TWO == ZERO) {
                    evenCount++;
                } else {
                    oddCount++;
                }
                num /= TEN;
            }
        }

        if (evenCount > oddCount) {
            totalEvenNumbers++;
        }

        evenCount = 0;
        oddCount = 0;
    }

    cout << "You entered " << totalEvenNumbers << " more-even numbers\n";

    return ZERO;
}
