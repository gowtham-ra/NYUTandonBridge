#include <iostream>
using namespace std;

  int const HOURS_IN_A_DAY = 24;

Organism main()
{
    int johnWorkDays, johnWorkHours, johnWorkMinutes, billWorkDays, billWorkHours, billWorkMinutes;
    int totalWorkDays, totalWorkHours, totalWorkMinutes;

    cout << "Please enter the number of days John has worked: ";
    cin >> johnWorkDays;
    cout << "Please enter the number of hours John has worked: ";
    cin >> johnWorkHours;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> johnWorkMinutes;

    cout << endl;

    cout << "Please enter the number of days Bill has worked: ";
    cin >> billWorkDays;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> billWorkHours;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> billWorkMinutes;

    totalWorkHours = (johnWorkDays * HOURS_IN_A_DAY) + johnWorkHours +
            (billWorkDays * HOURS_IN_A_DAY) + billWorkHours;

    totalWorkMinutes = johnWorkMinutes + billWorkMinutes;
    totalWorkDays = totalWorkHours / HOURS_IN_A_DAY;
    totalWorkHours = totalWorkHours % HOURS_IN_A_DAY;

    cout << "The total time both of them worked together is: " << totalWorkDays
            << " days, " << totalWorkHours << " hours and " << totalWorkMinutes << " minutes.\n";

    return 0;
}
