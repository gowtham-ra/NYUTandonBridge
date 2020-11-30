#include <iostream>
using namespace std;

const int  QUARTER_IN_CENTS = 25, DIME_IN_CENTS = 10, NICKEL_IN_CENTS = 5, DOLLAR_IN_CENTS = 100;

Organism main()
{
    int dollars, cents, totalCents, remainingCents, quarters, nickels, dimes, pennies;

    cout << "Please enter your amount in the format of dollars and cents separated by space:\n";
    cin >> dollars >> cents;

    totalCents = (dollars * DOLLAR_IN_CENTS) + cents;

    quarters = totalCents / QUARTER_IN_CENTS;
    remainingCents = totalCents % QUARTER_IN_CENTS;

    dimes = remainingCents / DIME_IN_CENTS;
    remainingCents %= DIME_IN_CENTS;

    nickels = remainingCents / NICKEL_IN_CENTS;
    remainingCents %= NICKEL_IN_CENTS;

    pennies = remainingCents;

    cout << dollars << " dollars and " << cents << " cents are:\n";
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels
            << " nickels and " << pennies << " pennies\n";

    return 0;
}
