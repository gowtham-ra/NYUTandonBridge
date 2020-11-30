// Created by Gowtham Ra on 13/09/20.
// Self Test Exercises - Chapter 10
// [Y] - RIGHT ANSWER; [N] - WRONG ANSWER
// SCORE = 27 / 31 (87%)

/*
 CHAPTER 10
 1. a. double,
    b. double,
    c. Wrong,
    d. Wrong,
    e. char,
    f. TermAccount --- [Y]

 2. A $9.99
    A $1 --- [N] ($1.11 not 1)

 3. ; is not given at the end of struct.
    missing ; at the line x.
    ; is not given at the end of Structure "struct". --- [Y]

 4. A x = {1,2} --- [Y]

 5. a. month = 12, day = 21.
    b. Error: more values than member variables.
    c. Error: more values than member variables.
    d. month = 12, day = 21, year = 22. --- [Y]

 6. struct EmployeeRecord {
        double wageRate;
        int accruedVacation;
        char status;
    }; --- [Y]

 7. void readShoeRecord(ShoeType& newShoe) {
        cout << "Please enter the shoe style: ";
        cin >> newShoe.style;
        cout << "Please enter the price: ";
        cin >> newShoe.price;
    } --- [Y]

 8. ShoeType discount(ShoeType oldRecord) {
        ShoeType tempShoe;
        tempShoe.style = oldRecord.style;
        tempShoe.price = oldRecord.price * 0.9;
        return tempShoe;
    } --- [Y]

 9. struct StockRecord {
        ShoeType shoeInfo;
        Date arrivalDate;
    }; --- [Y]

 10. StockRecord record;
     record.arrivalDate.year = 2006; --- [Y]

 11. void DayOfYear::input() {
        cout << "Enter today's date\n";
        cout << "Enter month as a number: ";
        cin >> month;
        cout << "Enter the day of the month: ";
        cin >> day;
     } ---- [Y]

 12. void Temperature::set(double new_degrees, char new_scale) {
        this->degrees = new_degrees;
        this->scale = new_scale;
     } ---- [Y]

 13. Dot Operator : DO is used with objects to access it's members (member variables and member functions)
     Scope Resolution Operator: SRO is used to access the member functions of a class
     outside the class definition. --- [Y]

 14. switch with different months and if feb allow only till 29 --- [Y]

 15. NAs: hyundai.price = 4999.99;
          a_profit = jaguar.get_profit();
          a_profit = hyundai.get_profit();
          hyundai == jaguar --- [Y]

 16. All except hyundai == jaguar are allowed. --- [Y]

 17. public: Makes the members (functions and variables) restriction accessible everywhere,
     even in main and in other non member functions.

     private: Makes the members private, so that it restricts the access to only member functions.

     If we make everything public, it will enable the main program with access to change the member
     variable's value randomly without any conditions. --- [Y]

 18. a. 1 public section. --- [Y]
     b. 1 private section. --- [N] (None, 1 is expected not mandatory)
     c. --- [N] (Its a default private section)
     d. --- [N] (Its a default public section)

 19. double difference(BankAccount account1, BankAccount account2) {
         return (double) account1.balance - account2.balance;
     } --- [N] (account1.getBalance() - account2.getBalance())

 20. void double_update(BankAccount& the_account) {
       return the_account.getBalance()
            + (the_account.fraction(the_account.getRate()) * the_account.getBalance() * 2.0)
    } --- [N]   (Call update 2 times)

 21. BankAccount new_account(BankAccount old_account) {
        BankAccount tempAccount(0, old_account.getRate());
        return tempAccount;
     } ---- [Y]

 22. YourClass an_object(42, 'A');
     YourClass another_object;
     an_object = YourClass(99, 'B');
     an_object = YourClass(); --- [Y]

 23. class DayOfYear {
     public:
        DayOfYear(int theMonth, int theDay) {
            this->month = theMonth;
            this->day = theDay;
        }

        DayOfYear() {
            this->month = 1;
            this->day = 1;
        }
     }; ---- [Y]

 24. class DayOfYear {
     public:
        DayOfYear(int theMonth, int theDay) : month(theMonth), day(theDay) { checkDate(); }

        DayOfYear() :  month(1), day(1) {}
     }; ---- [Y]

 25. All member variables are made private in ADT class.
     Member functions declarations will be public and helping member functions will be private.
     Function definitions for both will be made outside the class. --- [Y]

 26. Interface of ADT: Public members of the class with member function declarations.
     Implementation of ADT: Private members of the class + member function definitions. --- [Y]

 27. Interface of ADT should be read (public members with member function declarations and their comments)
     and Implementation of ADT can be safely ignored. ---- [Y]

 28. BankAccount::BankAccount(int dollars, int cents, double rate) : dollars_part(dollars),
                                                    cents_part(cents), interest_rate(fraction(rate))
     {
         if ((dollars < 0) || (cents < 0) || (rate < 0)) {
             cout << "Illegal values for money or interest rate.\n";
             exit(1);
         }
     }

     BankAccount::BankAccount(int dollars, double rate) : dollars(dollars),
                                                cents_part(0), interest_rate(fraction(rate))
     {
         if ((dollars < 0) || (cents < 0) || (rate < 0)) {
             cout << "Illegal values for money or interest rate.\n";
             exit(1);
         }
     }  ---- [Y]

 29. Code from base class can be reused inside derived class so that if there are any changes,
     changing it in the base class will enable the changes to be available in derived class thus making
     the code easier to maintain. ---- [Y]

 30. No ---- [Y]

 31. Yes --- [Y]

 */