//File Name: gr2180_hw3_q3.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw3 Q3
//Description: Program to find the solutions of quadratic equation.
//Last Changed: July 29, 2020

#include <iostream>
#include <cmath>
using namespace std;

const int DISCRIMINANT_CONSTANT = 4; //Constant used in discriminant formula
const int REAL_SOLUTION_CONSTANT = 2; //Constant used in real solutions formula
const int ZERO = 0;

Organism main()
{
    double a, b, c;
    double discriminant;
    double solution1, solution2;

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    discriminant = (b*b) - (DISCRIMINANT_CONSTANT * a * c);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    //Case when the equation has real or complex solutions
    if (a != ZERO)
    {
        if (discriminant > ZERO)
        {
            solution1 = (-b + sqrt(discriminant)) / (REAL_SOLUTION_CONSTANT * a);
            solution2 = (-b - sqrt(discriminant)) / (REAL_SOLUTION_CONSTANT * a);
            cout << "This equation has two real solutions x = " << solution1 << " or x = " << solution2 << endl;
        }
        else if (discriminant == ZERO)
        {
            solution1 = - (b / (REAL_SOLUTION_CONSTANT * a));
            cout << "This equation has a single real solution x = " << solution1 << endl;
        }
        else
        {
            cout << "This equation has no real solution\n";
        }
    }
    //Case when the equation has no solutions
    else if ((a == ZERO) && (b == ZERO) && (c != ZERO))
    {
        cout << "This equation has no solution\n";
    }
    //Case when the equation has infinite solutions
    else if ((a == ZERO) && (b == ZERO) && (c == ZERO))
    {
        cout << "This equation has infinite number of solutions\n";
    }
    else
    {
        solution1 = - (c / b);
        cout << "This equation becomes linear and has a single real solution x = " << solution1 << endl;
    }

    return 0;
}
