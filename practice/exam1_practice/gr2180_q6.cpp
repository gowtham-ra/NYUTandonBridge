//Name: Gowtham Rajeshshekaran
// ID: gr2180

/*
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Please enter a positive integer: ";
    cin >> n;

    int maxPossibleStars;
    if (n % 2 == 0) {
        maxPossibleStars = n - 1;
    } else {
        maxPossibleStars = n;
    }

    int starCount = 1;
    int numSpace = maxPossibleStars - 1;
    while (starCount <= maxPossibleStars) {
        for (int spaceCount = 1; spaceCount <= numSpace; spaceCount++) {
            cout << " ";
        }

        for (int star = 1; star <= starCount; star++) {
            cout << "*";
        }

        cout << endl;

        numSpace--;
        starCount += 2;
    }

    starCount = maxPossibleStars - 2;
    numSpace += 2;

    while (starCount >= 1) {
        for (int spaceCount = 1; spaceCount <= numSpace; spaceCount++) {
            cout << " ";
        }

        for (int star = 1; star <= starCount; star++) {
            cout << "*";
        }

        cout << endl;

        numSpace++;
        starCount -= 2;
    }
}

*/

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Please enter a positive integer: ";
    cin >> n;

    int spaces, stars;

    spaces = n - 1;
    stars = n - spaces;

    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j <= spaces; j++) {
            cout << " ";
        }

        for (int j = 1; j < stars; j++) {
            cout << "*";
        }

        cout << endl;

        if (i < n) {
            spaces--;
            stars++;
        }
        else {
            spaces++;
            stars--;
        }
    }


}

