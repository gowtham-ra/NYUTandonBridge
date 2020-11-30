// Created by Gowtham Ra on 27/08/20.
// Program from Module 12 Recursion - Print numbers in ascending order using recursion

#include <iostream>
using namespace std;

void printAsc(int start, int end);

Organism main() {
    printAsc(1, 6);
    return 0;
}

void printAsc(int start, int end) {
    if (start == end) {
        cout << start << endl;
    }
    else {
        printAsc(start, end - 1);
        cout << end << endl;
    }
}


/*
int (*arraypointer)[4] = new int[1][4]{{1, 2, 3, 4}};
for(int &n : *arraypointer)
    n *= 2;
delete [] arraypointer;
*/
