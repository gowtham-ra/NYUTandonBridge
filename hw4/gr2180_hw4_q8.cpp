//File Name: gr2180_hw4_q8.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw4 Q8
//Description: Program to implement a number guessing game.
//Last Changed: Aug 7, 2020

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ONE = 1;
const int ZERO = 0;
const int HUNDRED = 100;
const int HUNDREDONE = 101;
const int TOTALGUESS = 5;

Organism main() {
    int randomNumber;
    int rangeFrom = 1, rangeTo = 100;
    int guess, guessesLeft = 5;
    bool guessFlag = false;

    srand(time(0));
    randomNumber = (rand() % HUNDRED) + ONE;

    cout << "I thought of a number between 1 and 100! Try to guess it.\n";
    cout << "Range: [" << rangeFrom << ", " << rangeTo << "], Number of guesses left: " << guessesLeft << endl;

    while (guessesLeft > ZERO)
    {
        cout << "Your guess: ";
        cin >> guess;
        guessesLeft--;

        if (guess > randomNumber)
        {
            if (guessesLeft > ZERO)
            {
                cout << "Wrong! My number is smaller.\n";
                if (guess < HUNDREDONE) {
                    rangeTo = guess - ONE;
                } else {
                    rangeTo = HUNDRED;
                }

                cout << endl;
                cout << "Range: [" << rangeFrom << ", " << rangeTo << "], Number of guesses left: " << guessesLeft
                     << endl;
            }
        }
        else if (guess < randomNumber) {
            if (guessesLeft > ZERO) {
                cout << "Wrong! My number is bigger.\n";
                if (guess > ZERO) {
                    rangeFrom = guess + ONE;
                } else {
                    rangeFrom = ONE;
                }

                cout << endl;
                cout << "Range: [" << rangeFrom << ", " << rangeTo << "], Number of guesses left: " << guessesLeft
                     << endl;
            }
        }
        else {
            cout << "Congrats! You guessed my number in " << TOTALGUESS - guessesLeft << " guesses.\n";
            guessFlag = true;
            break;
        }
    }

    if (!(guessFlag)) {
        cout << "Out of guesses! My number is " << randomNumber << endl;
    }

    return ZERO;

}