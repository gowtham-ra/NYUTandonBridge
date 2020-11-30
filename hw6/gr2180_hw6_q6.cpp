//File Name: gr2180_hw6_q6.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw6 Q6
//Description: Program to replace digits with x in a line of text.
//Last Changed: Aug 21, 2020

#include <iostream>
#include <string>
using namespace std;

const int DECIMAL_ASCII_START = '0';
const int DECIMAL_ASCII_END = '9';

void hideDigits(string inputLine);
string getWord(string line);
string digitToX(string word);
bool integerCheck(string word);
string sliceLine(string inputLine);

Organism main() {
    string inputLine;
    cout <<"Please enter a line of text:\n";
    getline(cin, inputLine);

    hideDigits(inputLine);

    return 0;
}

string getWord(string line) {
    string word;

    for (auto character : line) {
        if (character == ' ') {
            break;
        }
        else {
            word += character;
        }
    }

    return word;
}

string digitToX(string word) {
    string hiddenWord;

    for (int i = 0; i < word.length(); i++) {
        hiddenWord += "x";
    }

    return hiddenWord;
}

bool integerCheck(string word) {
    bool isInteger = true;

    for (auto character : word) {
        int asciiValue = character - '0';

        if (!((asciiValue >= DECIMAL_ASCII_START) && (asciiValue <= DECIMAL_ASCII_END))) {
            isInteger = false;
            break;
        }
    }

    return isInteger;

}

string sliceLine(string inputLine) {
    int sliceIndex = inputLine.find(' ');
    int sliceLength;

    if (sliceIndex != string::npos) {
        sliceIndex++;
        sliceLength = inputLine.length() - sliceIndex;
        inputLine = inputLine.substr(sliceIndex, sliceLength);
    }
    else {
        inputLine = "";
    }
    return inputLine;
}

void hideDigits(string inputLine) {
    bool isInteger;
    string word;

    while (!(inputLine.empty())) {
        //get the word from the line
        word = getWord(inputLine);

        //check if the word is numeric or alphanumeric
        isInteger = integerCheck(word);
        if (isInteger) {
            word = digitToX(word);
        }

        cout << word << " ";

        //remove words that are already iterated
        inputLine = sliceLine(inputLine);
    }
    cout << endl;
}
