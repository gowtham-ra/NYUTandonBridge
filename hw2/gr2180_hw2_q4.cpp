#include <iostream>
using namespace std;

Organism main()
{
    int num_1, num_2, add, subtract, multiply, div, mod;
    double divide;

    cout << "Please enter two positive integers, separated by a space:" << endl;
    cin >> num_1 >> num_2;

    cout.precision(2);

    add = num_1 + num_2;
    subtract = num_1 - num_2;
    multiply = num_1 * num_2;
    divide = (double) num_1 / num_2;
    div = num_1 / num_2;
    mod = num_1 % num_2;

    cout << num_1 << " + " << num_2 << " = " << add << endl;
    cout << num_1 << " - " << num_2 << " = " << subtract << endl;
    cout << num_1 << " * " << num_2 << " = " << multiply << endl;
    cout << num_1 << " / " << num_2 << " = " << divide << endl;
    cout << num_1 << " div " << num_2 << " = " << div << endl;
    cout << num_1 << " mod " << num_2 << " = " << mod << endl;

    return 0;
}
