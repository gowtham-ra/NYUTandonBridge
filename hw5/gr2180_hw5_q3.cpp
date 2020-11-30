//File Name: gr2180_hw5_q3.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw5 Q3
//Description: Program to print the year calendar for the given year.
//Last Changed: Aug 14, 2020

#include <iostream>
#include <string>
using namespace std;

const int DAYS_IN_A_WEEK = 7;
const int THIRTY_DAYS = 30;
const int THIRTY_ONE_DAYS = 31;
const int FEB_NORMAL_DAYS = 28;
const int FEB_LEAP_DAYS = 29;
const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int EIGHT = 8;
const int NINE = 9;
const int TEN = 10;
const int ELEVEN = 11;
const int TWELVE = 12;
const int HUNDRED = 100;
const int FOUR_HUNDRED = 400;

int printMonthCalendar(int numOfDays, int startingDay);
//Prints a monthly calendar with "numOfDays" days and "startingDay" as starting day

bool leapYearCheck(int year);
//Checks if the given year is a leap year

void printYearCalendar(int year, int startingDay);
//Prints the year calendar for the given year and startingDay

Organism main() {
    int startingDay, year;

    cout << "Please enter the year: ";
    cin >> year;
    cout << "Enter the starting day of the month (1 for Mon, 2 for Tue, etc): ";
    cin >> startingDay;

    printYearCalendar(year, startingDay);
    return ZERO;
}

int printMonthCalendar(int numOfDays, int startingDay) {
    int numSpace = startingDay - ONE; // No of empty days before the starting day.

    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";

    //printing spaces based on starting day
    for (int space = 1; space <= numSpace; space++) {
        cout << "\t";
    }

    //printing the dates
    for (int date = 1; date <= numOfDays; date++) {
        cout << date << "\t";
        startingDay++;

        if ((startingDay > DAYS_IN_A_WEEK) && (date != numOfDays)) {
            cout << endl;
            startingDay = 1;
        }
    }

    return startingDay;
}

bool leapYearCheck(int year) {
    if (year % FOUR != ZERO) {
        return false;
    }
    else if (year % HUNDRED != ZERO) {
        return true;
    }
    else if (year % FOUR_HUNDRED != ZERO)
        return false;
    else
        return true;
}

void printYearCalendar(int year, int startingDay) {
    string month;
    int numOfDays;
    bool isLeapYear = leapYearCheck(year);

    for (int monthNum = 1; monthNum <= TWELVE; monthNum++){
        switch (monthNum) {
            case ONE:
                month = "January";
                numOfDays = THIRTY_ONE_DAYS;
                break;

            case TWO:
                month = "February";
                if(isLeapYear) {
                    numOfDays = FEB_LEAP_DAYS;
                }
                else
                    numOfDays = FEB_NORMAL_DAYS;
                break;

            case THREE:
                month = "March";
                numOfDays = THIRTY_ONE_DAYS;
                break;

            case FOUR:
                month = "April";
                numOfDays = THIRTY_DAYS;
                break;

            case FIVE:
                month = "May";
                numOfDays = THIRTY_ONE_DAYS;
                break;

            case SIX:
                month = "June";
                numOfDays = THIRTY_DAYS;
                break;

            case SEVEN:
                month = "July";
                numOfDays = THIRTY_ONE_DAYS;
                break;

            case EIGHT:
                month = "August";
                numOfDays = THIRTY_ONE_DAYS;
                break;

            case NINE:
                month = "September";
                numOfDays = THIRTY_DAYS;
                break;
            case TEN:
                month = "October";
                numOfDays = THIRTY_ONE_DAYS;
                break;
            case ELEVEN:
                month = "November";
                numOfDays = THIRTY_DAYS;
                break;
            case TWELVE:
                month = "December";
                numOfDays = THIRTY_ONE_DAYS;
                break;
        }

        cout << month << " " << year << endl;
        startingDay = printMonthCalendar(numOfDays, startingDay);
        cout << endl << endl;

        if (startingDay > DAYS_IN_A_WEEK) {
            startingDay %= DAYS_IN_A_WEEK;
        }
    }
}


