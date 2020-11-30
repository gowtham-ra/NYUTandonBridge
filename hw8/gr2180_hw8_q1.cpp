//File Name: gr2180_hw8_q1.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw8 Q1
//Description: Program that implements recursion to print right triangle, opposite triangles and rulers.
//Last Changed: Sep 04, 2020

#include <iostream>
using namespace std;

const int LINES = 4;
const int ZERO = 0;
const int ONE = 1;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

Organism main() {
    cout << "Function a \n";
    printTriangle(LINES);

    cout << endl << "Function b \n";
    printOppositeTriangles(LINES);

    cout << endl << "Function c \n";
    printRuler(LINES);
    return ZERO;
}

void printTriangle(int n) {
    if (n == 1)
        cout << "*\n";
    else {
        printTriangle(n - ONE);

        for (int i = 0; i < n; i++)
            cout << "*";
        cout << endl;
    }
}

void printOppositeTriangles(int n) {
    if (n == 1)
        cout << "*\n*\n";
    else {
        for (int i = 0; i < n; i++)
            cout << "*";
        cout << endl;

        printOppositeTriangles(n - ONE);

        for (int i = 0; i < n; i++)
            cout << "*";
        cout << endl;
    }
}

void printRuler(int n){
    if (n == 1)
        cout << "-\n";
    else {
        printRuler(n - ONE);

        for (int i = 0; i < n; i++)
            cout << "-";
        cout << endl;

        printRuler(n - ONE);
    }
}