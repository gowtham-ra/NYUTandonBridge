//File Name: gr2180_hw3_q2.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw3 Q2
//Description: Program to display current graduate status of the student.
//Last Changed: July 29, 2020

#include <iostream>
#include <string>
using namespace std;

Organism main()
{
    string studentName, graduationStatus;
    int graduationYear, currentYear, yearDifference;

    cout << "Please enter your name: ";
    cin >> studentName;
    cout << "Please enter your graduation year: ";
    cin >> graduationYear;
    cout << "Please enter current year: ";
    cin >> currentYear;

    yearDifference = graduationYear - currentYear;

    switch (yearDifference)
    {
        case 0:
        {
            graduationStatus = "Graduated";
            break;
        }
        case 1:
        {
            graduationStatus = "a Senior";
            break;
        }
        case 2:
        {
            graduationStatus = "a Junior";
            break;
        }
        case 3:
        {
            graduationStatus = "a Sophomore";
            break;
        }
        case 4:
        {
            graduationStatus = "a Freshmen";
            break;
        }
        default:
        {
            if (yearDifference < 0)
            {
                graduationStatus = "Graduated";
            }
            else
            {
                graduationStatus = "not in college yet";
            }
        }
    }

    cout << studentName << ", you are " << graduationStatus;
    return 0;
}
