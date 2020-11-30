//File Name: gr2180_hw3_q6.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw3 Q6
//Description: Program to compute the cost of a long distance call.
//Last Changed: July 29, 2020

#include <iostream>
#include <string>
using namespace std;

const double RATE_WEEKEND = 0.15;
const double RATE_WEEKDAY_PEAK_HOURS = 0.40;
const double RATE_WEEKDAY_NON_PEAK_HOURS = 0.25;
const int PEAK_HOUR_START_TIME = 8;
const int PEAK_HOUR_END_TIME = 18;

Organism main()
{
    int callDuration;
    int callTimeHour24, callTimeMinutes;
    char colon;
    string callDay;
    double callRate,callCost;

    cout << "Please enter the day of the call as two character string (Mo, Tu, We, Th, Fr, Sa, Su): ";
    cin >> callDay;
    if ((callDay != "Mo") && (callDay != "Tu") && (callDay != "We") && (callDay != "Th") && (callDay != "Fr") && (callDay != "Sa") && (callDay != "Su"))
    {
        cout << "Please enter a valid two character string as given";
        return 1;
    }

    cout << "Please enter the call start time in 24-hour notation: ";
    cin >> callTimeHour24 >> colon >> callTimeMinutes;
    cout << "Please enter the call duration (in minutes): ";
    cin >> callDuration;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if ((callDay == "Sa") || (callDay == "Su"))
    {
        callRate = RATE_WEEKEND;
    }
    else
    {
        if ((callTimeHour24 >= PEAK_HOUR_START_TIME) && (callTimeHour24 <= PEAK_HOUR_END_TIME))
        {
            callRate = RATE_WEEKDAY_PEAK_HOURS;
        }
        else
        {
            callRate = RATE_WEEKDAY_NON_PEAK_HOURS;
        }
    }

    callCost = callRate * double (callDuration);
    cout << "The cost of the call is $" << callCost << endl;

    return 0;
}

