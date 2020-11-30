//File Name: gr2180_hw6_q2.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw6 Q2
//Description: Program to check if the given word is a palindrome or not.
//Last Changed: Aug 21, 2020

#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(string str);

Organism main() {
    string word;

    cout << "Please enter a word: ";
    cin >> word;

    if (isPalindrome(word)) {
        cout << word << " is a palindrome\n";
    }
    else {
        cout << word << " is not a palindrome\n";
    }

    return 0;
}

bool isPalindrome(string str) {
    bool isPalindrome = true;

    for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            isPalindrome = false;
            break;
        }
    }

    return isPalindrome;
}