//
// Created by Gowtham Ra on 03/09/20.
//

#include <iostream>
using namespace std;

void towerOfHanoi (int disk, char source, char dest, char temp);

int main() {
    towerOfHanoi(4,'A', 'B', 'C');
    return 0;
}

void towerOfHanoi (int disk, char source, char dest, char temp) {
    if (disk == 1) {
        cout << "Move disk " << disk << " from " << source << " to " << dest << endl;
        return;
    }
    else {
        towerOfHanoi(disk - 1, source, temp, dest);
        cout << "Move disk " << disk << " from " << source << " to " << dest << endl;
        towerOfHanoi(disk - 1, temp, dest, source);
    }
}