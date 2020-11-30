//File Name: gr2180_hw3_q4.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw3 Q4
//Description: Program to round real numbers using different rounding methods.
//Last Changed: July 29, 2020

#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;
const int ONE = 1;
const int ZERO = 0;
const double DECIMAL_ZERO = 0.00;
const double DECIMAL_FIFTY = 0.50;

Organism main()
{
    double number, fractionalPart;
    int method;
    int intNumber, roundedNumber;

    cout << "Please enter a Real number:\n";
    cin >> number;
    cout << "Choose your rounding method:\n" << "1. Floor round\n"
        << "2. Ceiling round\n" << "3. Round to the nearest whole number\n";
    cin >> method;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    intNumber = number;

    //Separating the fractional value from positive or negative real numbers
    if (number >= ZERO)
        fractionalPart = number - intNumber;
    else
        fractionalPart = intNumber - number;

    switch (method)
    {
        case FLOOR_ROUND:
        {
            if ((intNumber < ZERO) && (fractionalPart > DECIMAL_ZERO))
            {
                roundedNumber = intNumber - ONE;
            }
            else
            {
                roundedNumber = intNumber;
            }
            break;
        }

        case CEILING_ROUND:
        {
            if ((intNumber >= ZERO) && (fractionalPart > DECIMAL_ZERO))
            {
                roundedNumber = intNumber + ONE;
            }
            else
            {
                roundedNumber = intNumber;
            }
            break;
        }

        case ROUND:
        {
            if (fractionalPart >= DECIMAL_FIFTY)
            {
                if (intNumber >= ZERO)
                {
                    roundedNumber = intNumber + ONE;
                }
                else
                {
                    roundedNumber = intNumber - ONE;
                }
            }
            else
            {
                roundedNumber = intNumber;
            }
            break;
        }

        default:
        {
            cout << "Please enter a valid number 1, 2 or 3\n";
            return 1;
        }
    }

    cout << roundedNumber << endl;
    return 0;
}
