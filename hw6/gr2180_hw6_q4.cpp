//File Name: gr2180_hw6_q4.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw6 Q4
//Description: Program to simulate randomized challenge-response system.
//Last Changed: Aug 21, 2020

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

const string PIN_NUMBER = "54321";
const char ZERO_CHAR = '0';
const int TOTAL_RAND_DIGITS = 3;
const int TOTAL_DIGITS = 10;
const int FIVE_DIGITS = 5;
const int ONE = 1;

void assignRandomNumbers(int arr[], int arrSize);
void printArrayToRandomDigitsMap(int arr[], int arrSize);
bool isValidPin(string input, int arr[], int arrSize);


Organism main() {

    int randomNumArray[TOTAL_DIGITS];

    assignRandomNumbers(randomNumArray, TOTAL_DIGITS);
    cout << "Please enter your PIN according to the following mapping:\n";
    printArrayToRandomDigitsMap(randomNumArray, TOTAL_DIGITS);

    string input;
    cin >> input;
    int inputSize = input.length();

    if (inputSize != FIVE_DIGITS) {
        cout << "Please enter 5-digit password";
        return 1;
    }

    bool validPin = isValidPin(input, randomNumArray, TOTAL_DIGITS);
    if (validPin) {
        cout << "Your PIN is correct\n";
    } else {
        cout << "Your PIN is not correct\n";
    }

    return 0;
}

void assignRandomNumbers(int arr[], int arrSize) {
    srand(time(0));

    for (int digit = 0; digit < arrSize; digit++) {
        arr[digit] = (rand() % TOTAL_RAND_DIGITS) + ONE;
    }
}

void printArrayToRandomDigitsMap(int arr[], int arrSize){
    cout << "PIN:  ";
    for (int i = 0; i < arrSize; i++) {
        cout << i << " ";
    }

    cout << endl;
    cout << "NUM:  ";

    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isValidPin(string input, int arr[], int arrSize) {
    bool validPin = true;

    for (int i = 0; i < FIVE_DIGITS; i++) {
        int targetNumber =  input[i];
        int pinNumber =  PIN_NUMBER[i] - ZERO_CHAR;

        for (int index = 0; index < arrSize; index++) {
            if (targetNumber == arr[index]) {
                if (index == pinNumber) {
                    break;
                }
            }
            else if (index == arrSize - ONE) {
                validPin = false;
                break;
            }
        }

        if ((!validPin)) {
            break;
        }
    }

    return validPin;
}