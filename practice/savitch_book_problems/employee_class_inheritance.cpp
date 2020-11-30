// Created by Gowtham Ra on 15/09/20.
// Program to demonstrate inheritance using class Employee.

#include <iostream>
#include <string>
using namespace std;

class Employee {
public:

    Employee();
    Employee(string theName, string theSsn);

    string getName() const;
    string getSsn() const;
    void setName(const string &theName);
    void setSsn(const string &theSsn);
    void setNetPay(double theNetPay);
    double getNetPay() const;
    void printCheck() const;

private:
    string name;
    string ssn;
    double netPay;
};

string Employee::getName() const {
    return name;
}

void Employee::setName(const string &theName) {
    this->name = theName;
}

string Employee::getSsn() const {
    return ssn;
}

void Employee::setSsn(const string &theSsn) {
    this->ssn = theSsn;
}

double Employee::getNetPay() const {
    return netPay;
}

void Employee::setNetPay(double theNetPay) {
    this->netPay = theNetPay;
}

Employee::Employee(string theName, string theSsn) : name(theName), ssn(theSsn), netPay(0) {}

Employee::Employee() : name("No name yet"), ssn("No ssn yer"), netPay(0) {}

void Employee::printCheck() const {
    cout << "\nERROR: print_check FUNCTION CALLED FOR AN \n"
    << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
    << "Check with the author of the program about this bug.\\n";

    exit(1);
}

class HourlyEmployee : public Employee {
public:
    HourlyEmployee();
    HourlyEmployee(string theName, string theSsn, double theWage, double theHours);
    void setRate(const double& theRate);
    void setHours(const double& theHours);
    double getRate() const;
    double getHours() const;
    void printCheck();

private:
    double wageRate;
    double hours;
};

HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0), hours(0) {}

HourlyEmployee::HourlyEmployee(string theName, string theSsn, double theWage, double theHours)
                : Employee(theName, theSsn), wageRate(theWage), hours(theHours) {}

void HourlyEmployee::setRate(const double &theRate) {
    this->wageRate = theRate;
}

void HourlyEmployee::setHours(const double &theHours) {
    this->hours = theHours;
}

double HourlyEmployee::getRate() const {
    return this->wageRate;
}

double HourlyEmployee::getHours() const {
    return this->hours;
}

void HourlyEmployee::printCheck() {
    setNetPay(hours * wageRate);
    cout << "\n_____________________________________________\n";
    cout << "Pay to the order of "  << getName() << endl;
    cout << "The sum of " << getNetPay() << " Dollars\n";
    cout << "_____________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << getSsn() << endl;
    cout << "Hourly Employee. \nHours worked: " << hours << " Rate: "
    << wageRate << " Pay: " << getNetPay() << endl;
    cout << "_____________________________________________";
}

class SalariedEmployee : public Employee {
public:
    SalariedEmployee();
    SalariedEmployee(string theName, string theSsn, double theSalary);
    void setSalary(const double& theSalary);
    double getSalary() const;
    void printCheck();

private:
    double salary;
};

SalariedEmployee::SalariedEmployee() : Employee(), salary(0) {}

SalariedEmployee::SalariedEmployee(string theName, string theSsn, double theSalary)
                : Employee(theName, theSsn), salary(theSalary) {}

void SalariedEmployee::setSalary(const double &theSalary) {
    this->salary = theSalary;
}

double SalariedEmployee::getSalary() const {
    return this->salary;
}

void SalariedEmployee::printCheck() {
    setNetPay(salary);
    cout << "\n_____________________________________________\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getNetPay() << " Dollars\n";
    cout << "________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << getSsn() << endl;
    cout << "Salaried Employee. Regular Pay: "
         << salary << endl;
    cout << "______________________________________________";
}

int main( ) {
    HourlyEmployee joe;

    joe.setName("Mighty Joe");
    joe.setSsn("123-45-6789");
    joe.setRate(20.50);
    joe.setHours(40);

    cout << "Check for " << joe.getName()
         << " for " << joe.getHours() << " hours.";
    joe.printCheck();
    cout << endl;

    SalariedEmployee boss("Mr. Big Shot", "987-65-4321", 10500.50);
    cout << "Check for " << boss.getName();
    boss.printCheck();


    return 0;
}
