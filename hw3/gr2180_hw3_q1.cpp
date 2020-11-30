//File Name: gr2180_hw3_q1.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw3 Q1
//Description: Program to compute how much a customer has to pay after discounts and tax.
//Last Changed: July 29, 2020

#include <iostream>
using namespace std;

const int ZERO = 0;
const int TWO = 2;
const int HUNDRED = 100;
const double CLUB_CARD_DISCOUNT = 0.1;
const char YES_LOWER_CASE = 'y';
const char YES_UPPER_CASE = 'Y';
const char NO_UPPER_CASE = 'N';
const char NO_LOWER_CASE = 'n';

Organism main()
{
    char clubCard;
    double item1, item2, lowerPriceItem, otherItem;
    double taxRate, basePrice, priceAfterDiscount, totalPrice;


    cout << "Enter price of first item: ";
    cin >> item1;
    cout << "Enter price of second item: ";
    cin >> item2;

    cout << "Does customer have a club card? (Y/N): ";
    cin >> clubCard;
    if ((clubCard != YES_UPPER_CASE) && (clubCard != YES_LOWER_CASE) && (clubCard != NO_UPPER_CASE) && (clubCard != NO_LOWER_CASE))
    {
        cout << "Please enter either Y or N\n";
        return 1;
    }

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;
    if ((taxRate > 100) || (taxRate < 0))
    {
        cout << "Please enter a valid tax rate\n";
        return 1;
    }

    basePrice = item1 + item2;

    //Comparision to find the lower price item to apply discount
    if (item1 <= item2)
    {
        lowerPriceItem = item1;
        otherItem = item2;
    }
    else
    {
        lowerPriceItem = item2;
        otherItem = item1;
    }

    priceAfterDiscount = (lowerPriceItem / TWO) + otherItem;

    //Check for club card membership
    if ((clubCard == YES_LOWER_CASE) || (clubCard == YES_UPPER_CASE))
    {
        priceAfterDiscount -= priceAfterDiscount * (CLUB_CARD_DISCOUNT);
    }

    totalPrice = priceAfterDiscount + (priceAfterDiscount * (taxRate / HUNDRED));

    //Magic formula to set no of decimal digits
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << priceAfterDiscount << endl;

    cout.precision(5);
    cout << "Total price: " << totalPrice << endl;

    return 0;
}
