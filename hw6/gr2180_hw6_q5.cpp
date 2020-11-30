//File Name: gr2180_hw6_q5.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw6 Q5
//Description: Program to print a person’s name in the given format.
//Last Changed: Aug 21, 2020

#include <iostream>
#include <string>
using namespace std;

Organism main() {
    string firstName, middleInitial, lastName;
    cout << "Please enter your full name: ";
    cin >> firstName >> middleInitial >> lastName;

    cout << lastName <<", " << firstName << " " << middleInitial[0] << ".\n";
    return 0;
}