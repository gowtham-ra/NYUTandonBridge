//File Name: gr2180_hw7_q1.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw7 Q1
//Description: Program to read a line of text and output number of words in the line
// and also the number of occurrences of each letter
//Last Changed: Aug 27, 2020

#include <iostream>
#include <string>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TOTAL_ALPHABETS = 26;
const int LOWERCASE_ASCII_CONVERSION_VALUE = 'a' - 'A'; //32
const int LOWERCASE_ASCII_STARTING_VALUE = 'a'; //97
const char UPPERCASE_A = 'A';
const char UPPERCASE_Z = 'Z';
const char LOWERCASE_A = 'a';
const char LOWERCASE_Z = 'z';

int wordCount(const string& line);
void computeLetterOccurrence(const string& line);
bool isAlpha(char character);
bool isUpper(char character);


Organism main() {
    string lineOfText;

    cout << "Please enter a line of text:\n";
    getline(cin, lineOfText);

    int numOfWords = wordCount(lineOfText);
    cout << numOfWords << "\t" << "words\n";

    computeLetterOccurrence(lineOfText);
    return ZERO;
}

int wordCount(const string& line) {
    int lineLength = line.length();
    int wordCount = 0;
    int index = 0;

    //Counting the number of words
    while (index != string::npos) {
        index = line.find(' ',index);
        if ((index != lineLength - ONE) && (index != ZERO))
            wordCount++;

        if (index != string::npos)
            index++;
    }
    return wordCount;
}

void computeLetterOccurrence(const string& line) {
    int alphabetCountArray[TOTAL_ALPHABETS] = {0};
    int index;

    //Counting the letters using an array with each index for an alphabet
    for (char letter : line) {
        if (isAlpha(letter)) {
            if (isUpper(letter)) {
                letter = (char) (letter + LOWERCASE_ASCII_CONVERSION_VALUE);
            }
            index = letter - LOWERCASE_ASCII_STARTING_VALUE;
            alphabetCountArray[index] += ONE;
        }
    }

    char letter;
    //Printing the letters occurred in the input line and their count
    for (int i = 0; i < TOTAL_ALPHABETS; i++) {
        if (alphabetCountArray[i] > ZERO) {
            letter = (char) (i + LOWERCASE_ASCII_STARTING_VALUE);
            cout << alphabetCountArray[i] << "\t" << letter << endl;
        }
    }
}

bool isAlpha(char character) {
    if (((character >= UPPERCASE_A) && (character <= UPPERCASE_Z))
    || (character >= LOWERCASE_A) && (character <= LOWERCASE_Z))
        return true;
    else
        return false;
}

bool isUpper(char character) {
    if ((character >= UPPERCASE_A) && (character <= UPPERCASE_Z))
        return true;
    else
        return false;
}