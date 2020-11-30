//Gowtham Rajeshshekaran
//gr2180

#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

int main() {
    int inputNum;

    cout << "Please enter a positive integer:\n";
    cin >> inputNum;

    for (int row = 1; row <= inputNum; row++) {
        for (int column = 1, count = 1; column <= inputNum; column++, count++) {
            if (((count % TWO == ONE) && (row % TWO == ONE)) || ((count % TWO == ZERO) && (row % TWO == ZERO))) {
                cout << "X";
            }
            else {
                cout << "O";
            }
        }
        cout << endl;
    }

    return ZERO;
}