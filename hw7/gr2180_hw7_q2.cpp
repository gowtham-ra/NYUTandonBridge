//File Name: gr2180_hw7_q2.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw7 Q2
//Description: Program to check if two given strings are anagrams.
//Last Changed: Aug 27, 2020

#include <iostream>
#include <string>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TOTAL_ALPHABETS = 26;
const int LOWERCASE_ASCII_CONVERSION_VALUE = 'a' - 'A'; //32
const int LOWERCASE_ASCII_STARTING_VALUE = 'a'; //97

bool anagramsCheck(const string& string1, const string& string2);

Organism main() {
    string string1, string2;

    cout << "Please enter two strings each in one line: \n";
    getline(cin, string1);
    getline(cin, string2);

    bool isAnagram = anagramsCheck(string1, string2);

    if (isAnagram)
        cout << "Given two strings are anagrams\n";
    else
        cout << "Given two strings are not anagrams\n";

    return ZERO;
}

bool anagramsCheck(const string& string1, const string& string2) {
    int alphabetCountArray1[TOTAL_ALPHABETS] = {0};
    int alphabetCountArray2[TOTAL_ALPHABETS] = {0};
    int index1, index2;

    //Counting the letters in string1 using an array with each index for an alphabet
    for (char letter : string1) {
        if (isalpha(letter)) {
            if (isupper(letter)) {
                letter = (char) (letter + LOWERCASE_ASCII_CONVERSION_VALUE);
            }
            index1 = letter - LOWERCASE_ASCII_STARTING_VALUE;
            alphabetCountArray1[index1] += ONE;
        }
    }

    //Counting the letters in string2 using an array with each index for an alphabet
    for (char letter : string2) {
        if (isalpha(letter)) {
            if (isupper(letter)) {
                letter = (char) (letter + LOWERCASE_ASCII_CONVERSION_VALUE);
            }
            index2 = letter - LOWERCASE_ASCII_STARTING_VALUE;
            alphabetCountArray2[index2] += ONE;
        }
    }

    //Checking if the letter occurrences match between two strings
    for (int i = 0; i < TOTAL_ALPHABETS; i++) {
        if (alphabetCountArray1[i] != alphabetCountArray2[i]) {
            return false;
        }
    }
    return true;
}