// Created by Gowtham Ra on 14/09/20.
// Self Test Exercises - Chapter 11
// [Y] - RIGHT ANSWER; [N] - WRONG ANSWER
// SCORE =

/*
 1. bool before(DayOfYear date1, DayOfYear date2) {
         int month1 = date1.getMonth();
         int day1 = date1.getDay();
         int month2 = date2.getMonth();
         int day2 = date2.getDay();

         if (month1 <= month2) {
             if (date1 < date2)
                 return true;
         } else
             return false;
     }

 2. Friend function of a class is a non member ordinary function which has been given access
    to private member variables of that class. Can be defined and worked like ordinary functions.
    Member function is declared inside the class and has direct access to it's private member variables.

 3. friend bool after(DayOfYear date1, DayOfYear date2);

 4. friend Money subtraction(Money amount1, Money amount2);

 5. void Money::output() {
        long positive_cents, dollars, cents;
        positive_cents = labs(all_cents);
        dollars = positive_cents / 100;
        cents = positive_cents % 100;

        if (all_cents < 0)
            cout << "-$" << dollars << '.';
        else
            cout << "$" << dollars << '.';

        if (cents < 10)
            cout << '0';

        cout << cents;
    }

 8. double Money::get_value() const {
        return (double) this->all_cents;
    }

 9. Adding const to input function will not lets ins to write the data to the given stream

 10. Differences: A copy of the arg is made and is worked upon in CBV
     whereas in CCBR, it is worked upon directly.
     Similarities: The value of the actual arg will not be changed in both ways.

 11. a. The value of x is not changed throughout the program.
     b. The member function f() does not change the values of its member variables.
     c. The values of the mem vars of the object passed as arg at x will not be changed.

 12. Both are functions but the syntax of the function call varies.

 13. friend bool operator <(const Money& amount1, const Money& amount2);

 14. friend bool operator <=(const Money& amount1, const Money& amount2);

 15. It is not possible because integers are predefined (primitive) data types.

 */


