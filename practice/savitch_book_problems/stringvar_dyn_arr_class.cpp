// Created by Gowtham Ra on 14/09/20.
// Program to demonstrate working of classes with dynamic memory using class StringVar.

#include <iostream>
#include <cstring>
using namespace std;

class StringVar {
public:
    StringVar(int size);
    StringVar(const char arr[]);
    StringVar();
    StringVar(const StringVar& stringObj); //Copy Constructor
    ~StringVar(); //Destructor

    int length() const;
    void inputLine(istream& ins);
    friend ostream& operator <<(ostream& outs, const StringVar& theString);

private:
    char *value;
    int maxSize;
};

StringVar::StringVar(int size) : maxSize(size) {
    value = new char[maxSize + 1];
    value[0] = '\0';
}

StringVar::StringVar(const char arr[]) : maxSize(strlen(arr)) {
    value = new char[maxSize + 1];
    strcpy(value, arr);
}

StringVar::StringVar() : maxSize(100) {
    value = new char[maxSize + 1];
    value[0] = '\0';
}

int StringVar::length() const {
    return strlen(value);
}

void StringVar::inputLine(istream &ins) {
    ins.getline(value,maxSize + 1);

}

ostream &operator<<(ostream &outs, const StringVar &theString) {
    outs << theString.value;
    return outs;
}

StringVar::~StringVar() {
    delete [] value;
    value = nullptr;
}

StringVar::StringVar(const StringVar &stringObj) : maxSize(stringObj.length()) {
    value = new char[maxSize + 1];
    strcpy(value, stringObj.value);
}

void conversation(int maxNameSize);

int main() {
    conversation(30);
    cout << "End of demonstration.\n";
    return 0;
}

void conversation(int maxNameSize) {
    StringVar yourName(maxNameSize), ourName("Borg");

    cout << "What is your name?\n";
    yourName.inputLine(cin);
    cout << "We are " << ourName << endl;
    cout << "We will meet again " << yourName << endl;
}


//Assignment operator overload?
//C-string more details on working with them. (char array, strlen(), strcpy() mainly)