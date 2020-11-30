//File Name: gr2180_hw7_q4.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw7 Q4
//Description: Program to create an array with all words in a sentence as elements.
//Last Changed: Aug 27, 2020

#include <iostream>
#include <string>
using namespace std;

const int ZERO = 0;
const int ONE = 1;

string* createWordsArray(string sentence, int& outWordsArrSize);

Organism main() {
    string sentence;
    string* strArrPtr = nullptr;
    int wordsArrSize = 0;

    sentence = "You can do it";
    strArrPtr = createWordsArray(sentence, wordsArrSize);

    for (int i = 0; i < wordsArrSize; i++) {
        cout << i + ONE << ". " << strArrPtr[i] << endl;
    }
    cout << "outWordsArrSize = " << wordsArrSize;

    delete[] strArrPtr;
    strArrPtr = nullptr;
    return ZERO;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    int wordCount = 0, index = 0;

    //Counting the number of words in the sentence with space as delimiter
    while (index != string::npos) {
        index = sentence.find(' ', index);
        wordCount++;

        if (index != string::npos)
            index++;
    }

    outWordsArrSize = wordCount;
    string* strArrPtr = new string[outWordsArrSize];
    index = 0;
    int sentenceLength = sentence.size();
    int sliceIndex, sliceLength;

    for (int i = 0; i < outWordsArrSize; i++) {
        sliceIndex = sentence.find(' ', index);

        //Finding the length of the word to slice
        if (sliceIndex != string::npos) {
            sliceLength = sliceIndex - index;
        } else {
            sliceLength = sentenceLength - index;
        }

        //Slicing each word from the sentence and saving it in the array
        strArrPtr[i] = sentence.substr(index, sliceLength);

        //Iterating to next letter in the sentence
        index += sliceLength + ONE;
    }

    return strArrPtr;
}
