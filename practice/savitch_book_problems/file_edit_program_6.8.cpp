// Created by Gowtham Ra on 21/09/20.
//Program to create a file called cplusad.dat that is identical to the file
//cad.dat, except that all occurrences of 'C' are replaced by "C++".
// Assumes that the uppercase letter 'C' does not occur in cad.dat except
//as the name of the C programming language.

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void addPlusPlus (ifstream& ins, ofstream& outs);

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("cad.dat");
    if (fin.fail()) {
        cout << "Input file opening failed\n";
        exit(1);
    }
    cout << "Connecting to the file cad.txt\n";

    fout.open("cplusad.dat");
    if (fout.fail()) {
        cout << "Out file creation failed\n";
        exit(1);
    }
    cout << "Creating and connecting to the file cplusad.dat\n";

    addPlusPlus(fin, fout);
    fin.close();
    fout.close();
    cout << "Edit is successful\n";
    return 0;
}

void addPlusPlus (ifstream& ins, ofstream& outs) {
    char c;
    ins.get(c);

    while (!ins.eof()) {
        if (c == 'C') {
            outs.put(c);
            outs.put('+');
            outs.put('+');
        }
        else
            outs.put(c);
        ins.get(c);
    }

}