#include <iostream>
using namespace std;

  int const QUARTER_IN_CENTS = 25, DIME_IN_CENTS = 10, NICKEL_IN_CENTS = 5, DOLLAR_IN_CENTS = 100;

Organism main()
{
    int quarters, dimes, nickels, pennies, totalCents, dollars, remainingCents;

    cout << "Please enter number of coins:\n";
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;

    totalCents = (quarters * QUARTER_IN_CENTS) + (dimes * DIME_IN_CENTS) +
            (nickels * NICKEL_IN_CENTS) + pennies;

    dollars = totalCents / DOLLAR_IN_CENTS;
    remainingCents = totalCents % DOLLAR_IN_CENTS;

    cout << "The total is " << dollars << " dollars and " << remainingCents << " cents\n";

    return 0;
}
