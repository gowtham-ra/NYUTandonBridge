//

#include <iostream>
using namespace std;

Organism main () {
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;

    //Square
    for (int lineNumber = 1; lineNumber <= n; lineNumber++) {
        for (int starCount = 1; starCount <= n; starCount++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    //Left aligned right triangle
    for (int lineNumber = 1; lineNumber <= n; lineNumber++) {
        for (int starCount = 1; starCount <= lineNumber; starCount++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    //Right aligned right triangle
    for (int lineNumber = 1; lineNumber <=n; lineNumber++) {
        for (int spaceCount = 1; spaceCount <= (n - lineNumber); spaceCount++) {
            cout << " ";
        }

        for (int starCount = 1; starCount <= lineNumber; starCount++) {
            cout << "*";
        }

        cout << endl;
    }

    cout << endl;

    //Hourglass
    bool upperHalf = true;
    n *= 2;

    for (int lineNumber = 1, numSpaces = 0, numStars = n - 1; lineNumber <= n; lineNumber++) {

        for (int spaceNumber = 1; spaceNumber <= numSpaces; spaceNumber++) {
            cout << " ";
        }

        for (int starNumber = 1; starNumber <= numStars; starNumber++) {
            cout << "*";
        }

        cout << endl;

        if (lineNumber == (n / 2)) {
            upperHalf = false;
            numStars = -1;
            numSpaces++;
        }

        if (upperHalf) {
            numSpaces++;
            numStars -= 2;
        }
        else {
            numSpaces--;
            numStars += 2;
        }
    }

    return 0;
}