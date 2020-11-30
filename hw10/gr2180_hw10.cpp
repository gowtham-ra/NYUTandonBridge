//File Name: gr2180_hw10.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw10
//Description: A system to keep track of the employee data and print their payroll information
//Last Changed: Sep 25, 2020

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Class declarations
class Employee;
class LListNode;
class LList;

typedef LListNode* LListNodePtr;

//Essential ordinary functions
void openInputFile(ifstream& ins);
int findMaxNetPayEmp(const LListNodePtr& head);
void swap(Employee& employee1, Employee& employee2);
void printPayRoll(const LListNodePtr& head);

class Employee {
public:
    //Constructors
    Employee() : name(""), idNum(0), payRate(0), workHours(0), netPay(0) {}

    Employee(string theName, int theId, double rate, int hours = 0, double pay = 0)
            : name(theName), idNum(theId), payRate(rate), workHours(hours), netPay(pay) {}

    //Accessor and Mutator Functions
    const string &getName() const {return name;}
    int getIdNum() const {return idNum;}
    void setWorkHours(int hours) {this->workHours += hours;}
    double getNetPay() const {return netPay;}
    void setNetPay() {this->netPay = (this->payRate * this->workHours);}

private:
    string name;
    int idNum;
    double payRate;
    int workHours;
    double netPay;
};

class LListNode {
public:
    //Constructors
    LListNode() : empData(Employee()), link(nullptr) {}
    LListNode(Employee newEmpData = Employee(), LListNode* newLink = nullptr) : empData(newEmpData), link(newLink) {}

    //Accessor and Mutator Functions
    Employee& getEmpData(){return this->empData;}
    LListNodePtr getLink() const {return link;}

    //Friend classes
    friend class LList;

private:
    Employee empData;
    LListNodePtr link;
};

class LList {
public:
    //Constructor
    LList() : head(nullptr){}

    //Destructor
    ~LList(){ clear();}

    //Member Functions
    LListNodePtr getHead() const {return this->head;}
    void insertAtEnd(const Employee& newData);
    int size() const;
    bool isEmpty() const {return (head == nullptr);}

private:
    LListNodePtr head;
    void clear();
};

//LList member function to insert nodes at the end of the list
void LList::insertAtEnd(const Employee &newData) {
    if (isEmpty()){
        head = new LListNode(newData);
    }
    else {
        LListNodePtr itr = head;
        while (itr->link != nullptr) {
            itr = itr->link;
        }
        itr->link = new LListNode(newData);
    }
}

//LList member function to return the size of the list
int LList::size() const {
   int count = 0;
   LListNodePtr itr = head;
   while (itr != nullptr) {
       count++;
       itr = itr->link;
   }
   return count;
}

//LList helper function to clear the list
void LList::clear() {
    LListNodePtr itr = head;
    while (itr != nullptr) {
        LListNodePtr discard = itr;
        itr = itr->link;
        delete discard;
    }
}

int main() {
    ifstream fin;
    LList list;

    //Open the first file
    openInputFile(fin);

    int empId;
    double empPayRate;
    char symbol;

    //Read inputs from first file
    while (fin >> empId) {
        fin >> empPayRate;
        fin.ignore(9999,' ');

        //Read employee name irrespective of different OS line separator formats (CRLF)
        string empName;
        fin.get(symbol);
        while ((!fin.eof()) && (symbol != '\r') && (symbol != '\n')) {
            empName += symbol;
            fin.get(symbol);
        }

        Employee employee(empName,empId,empPayRate);
        list.insertAtEnd(employee);
    }
    cout << "Inputs read from file 1 successfully!\n";
    fin.close();

    //Open the second file
    openInputFile(fin);
    int empWorkHours;
    LListNodePtr itr = list.getHead();

    //Read inputs from second file
    while (fin >> empId) {
        fin >> empWorkHours;
        fin.ignore(9999,'\n');

        //Iterate the list to find matching employee
        while (itr != nullptr) {
            if (itr->getEmpData().getIdNum() == empId) {
                //Set employee working hours and net pay
                itr->getEmpData().setWorkHours(empWorkHours);
                itr->getEmpData().setNetPay();
                break;
            }
            else
                itr = itr->getLink();
        }
    }
    cout << "Inputs read from file 2 successfully!\n";
    fin.close();

    int maxId;
    LListNodePtr posPtr = list.getHead();

    //Sort the linked list based on employee's net pay value
    for (int i = 0; i < list.size(); i++) {
        itr = posPtr;
        maxId = findMaxNetPayEmp(posPtr);

        //End the sort if all remaining employees have 0 net pay
        if (maxId == -1)
            break;

        while (itr != nullptr) {
            if (itr->getEmpData().getIdNum() == maxId)
                break;
            itr = itr->getLink();
        }

        int emp1Id = posPtr->getEmpData().getIdNum();
        int emp2Id = itr->getEmpData().getIdNum();
        //Swap if both employees are not same
        if (emp1Id != emp2Id)
            swap(posPtr->getEmpData(), itr->getEmpData());

        posPtr = posPtr->getLink();
    }

    //Print payRoll information
    printPayRoll(list.getHead());

    return 0;
}

//Boiler plate function to open input file
void openInputFile(ifstream &ins) {
    string fileName;
    cout << "Enter the input file name: ";
    cin >> fileName;

    ins.open(fileName);

    while (!ins) {
        cout << "Input file opening failed\n";
        cout << "Please enter the input file name again: ";
        cin >> fileName;
        ins.clear();
        ins.open(fileName);
    }
}

//Function that returns the employee ID with maximum net pay from the given node
int findMaxNetPayEmp(const LListNodePtr& head) {
    double maxPay = 0;
    int maxId = -1;
    LListNodePtr itr = head;

    while (itr != nullptr) {
        if (itr->getEmpData().getNetPay() > maxPay) {
            maxPay = itr->getEmpData().getNetPay();
            maxId = itr->getEmpData().getIdNum();
        }
        itr = itr->getLink();
    }
    return maxId;
}

//Function that swaps the two given employee objects
void swap(Employee& employee1, Employee& employee2) {
    Employee temp = employee1;
    employee1 = employee2;
    employee2 = temp;
}

//Function to print the payroll data
void printPayRoll(const LListNodePtr& head) {
    string empName;
    double empNetPay;

    LListNodePtr itr = head;
    cout << "********Payroll Information********\n";
    while (itr != nullptr) {
        empName = itr->getEmpData().getName();
        empNetPay = itr->getEmpData().getNetPay();
        cout << empName << ", $" << empNetPay << endl;
        itr = itr->getLink();
    }
    cout << "*********End Payroll**************\n";
}