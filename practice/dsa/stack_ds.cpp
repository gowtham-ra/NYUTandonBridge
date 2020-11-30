// Created by Gowtham Ra on 29/09/20.
// Program to implement stack data structure

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void evalPostFix();
void strReverse();
void balanceSymbols();
bool hasHigherPrecedence(char prev, char curr);
void infixToPostfix();
int GetOperatorWeight(char op);
int IsRightAssociative(char op);

template <typename T>
class ArrStack {
private:
    vector<T> theArr;
    int topOfStack = -1;

public:
    void push(const T& item);
    void pop();
    T peek() const;
    bool isEmpty() const { return (topOfStack == -1);};
};

template<typename T>
T ArrStack<T>::peek() const {
    if (isEmpty()) {
        cout << "The stack is empty\n";
        exit(1);
    }
    else
        return theArr[topOfStack];
}

template<typename T>
void ArrStack<T>::push(const T &item) {
    theArr.push_back(item);
    topOfStack++;
}

template<typename T>
void ArrStack<T>::pop() {
    if (isEmpty()) {
        cout << "The stack is empty\n";
        exit(1);
    }
    else {
        theArr.pop_back();
        topOfStack--;
    }
}

template <typename T>
class Stack;

template <typename T>
class StackNode {
private:
    T data;
    StackNode<T>* link;
public:
    explicit StackNode(T item, StackNode<T>* ptr = nullptr) : data(item), link(ptr) {}
    friend class Stack<T>;
};

template <typename T>
class Stack {
private:
    StackNode<T>* top = nullptr;
public:
    void push(const T& item);
    T pop();
    T peek() const;
    bool isEmpty() const { return (this->top == nullptr);}
};

template <typename T>
void Stack<T>::push(const T& item) {
    auto* itemNode = new StackNode<T>(item, top);
    top = itemNode;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "The stack is empty\n";
        exit(1);
    }
    else {
        T item = top->data;
        StackNode<T>* discard = top;
        top = top->link;
        delete discard;
        return item;
    }
}

template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        cout << "The stack is empty\n";
        exit(1);
    }
    else
        return top->data;
}

int main() {
    //Evaluation of Postfix expressions
    evalPostFix();
    //For prefix evaluation read from right to left

    //Reversing a string
//    strReverse();

    //Balancing symbols
//    balanceSymbols();

    //Infix to postfix conversion
    infixToPostfix();

    return 0;
}

void infixToPostfix() {
    Stack<char> symbolStack;
    string input;
    cout << "Enter the infix expression: ";
    getline(cin, input);
    string outString;
    char symbol;

    for (auto ch : input) {
        if (ch == ' ' || ch == ',')
            continue;

        else if (isalnum(ch))
            outString += ch;

        else {
            if (ch == '(')
                symbolStack.push(ch);
            else if (ch == ')') {
                while (!symbolStack.isEmpty() && symbolStack.peek() != '(') {
                    symbol = symbolStack.pop();
                    outString += symbol;
                }
                symbolStack.pop();
            }
            else {
                while (!symbolStack.isEmpty() && symbolStack.peek() != '('
                       && hasHigherPrecedence(symbolStack.peek(), ch)) {
                    symbol = symbolStack.pop();
                    outString += symbol;
                }
                symbolStack.push(ch);
            }
        }
    }
    while (!symbolStack.isEmpty()) {
        symbol = symbolStack.pop();
        outString += symbol;
    }
    cout << "Postfix expression: " << outString << endl;
}

bool hasHigherPrecedence(const char prev, const char curr){
    int op1Weight = GetOperatorWeight(prev);
    int op2Weight = GetOperatorWeight(curr);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if(op1Weight == op2Weight)
    {
        if(IsRightAssociative(prev)) return false;
        else return true;
    }
    return op1Weight > op2Weight;
}

int GetOperatorWeight(char op)
{
    int weight = -1;
    switch(op)
    {
        case '+':
        case '-':
            weight = 1;
        case '*':
        case '/':
            weight = 2;
        case '$':
            weight = 3;
    }
    return weight;
}

int IsRightAssociative(char op)
{
    if(op == '$') return true;
    return false;
}

void balanceSymbols() {
    Stack<char> symbolsStack;
    string input;
    bool valid = true;

    cout << "Enter the expression: ";
    getline(cin, input);

    for (auto ch : input) {
        if (ch == '(' || ch == '[' || ch == '{')
            symbolsStack.push(ch);

        else if (ch == ')') {
            if (!symbolsStack.isEmpty() && symbolsStack.pop() == '(')
                continue;
            else {
                valid = false;
                break;
            }
        }
        else if (ch == ']') {
            if (!symbolsStack.isEmpty() && symbolsStack.pop() == '[')
                continue;
            else {
                valid = false;
                break;
            }
        }
        else if (ch == '}') {
            if (!symbolsStack.isEmpty() && symbolsStack.pop() == '{')
                continue;
            else {
                valid = false;
                break;
            }
        }
        else
            continue;
    }

    if (!symbolsStack.isEmpty())
        valid = false;

    if (valid)
        cout << "Valid Expression\n";
    else
        cout << "Invalid Expression\n";
}

void strReverse() {
    Stack<char> stringStack;
    string word = "HELLO";

    for (auto letter : word) {
        stringStack.push(letter);
    }

    while (!stringStack.isEmpty())
        cout << stringStack.pop();
}

void evalPostFix() {
    Stack<int> postFix;
    string input;
    cout << "Enter the postfix expression: ";
    getline(cin, input);

    for (auto op : input) {
        if (isnumber(op)) {
            int no =  op - '0';
            postFix.push(no);
        }
        else {
            int op2 = postFix.pop();
            int op1 = postFix.pop();
            int res;

            switch (op) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
                default:
                    cout << "Operator not defined\n";
                    exit(1);
            }
            postFix.push(res);
        }
    }
    cout << "Value = " << postFix.pop();
}
