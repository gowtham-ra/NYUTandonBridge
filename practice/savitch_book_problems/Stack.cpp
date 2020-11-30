/*
// Created by Gowtham Ra on 22/09/20.
// Program to implement stack data structure and use it in an example - Printing the word backwards
// Items are added and removed at the top which is the head of the linked list

#include <iostream>
using namespace std;

struct StackFrame {
    char data;
    StackFrame* link;
};

typedef StackFrame* StackFramePtr;

class Stack {
public:
    Stack();
    Stack(const Stack& theStack);
    ~Stack();

    void push(char symbol);
    char pop();
    bool empty() const;

private:
    StackFramePtr top;
};

Stack::Stack() : top(nullptr) {}

//Memorise this. You suck at this!
Stack::Stack(const Stack &theStack) {
    if (theStack.empty())
        top = nullptr;
    else {
        StackFramePtr oldPtr = theStack.top;
        StackFramePtr newPtr;
        top = new StackFrame;
        top->data = oldPtr->data;
        top->link = nullptr;
        oldPtr = oldPtr->link;

        while (oldPtr != nullptr) {
            newPtr = new StackFrame;
            newPtr->data = oldPtr->data;
            newPtr->link = top;
            top = newPtr;
            oldPtr = oldPtr->link;
        }
    }
}

Stack::~Stack() {
    char next;
    while (!empty()){
        next = pop();
    }
}

void Stack::push(char symbol) {
    StackFramePtr temp = new StackFrame;
    temp->data = symbol;
    temp->link = top;
    top = temp;
}

char Stack::pop() {
    if (empty()) {
        cout << "The stack is empty\n";
        exit(1);
    }
    else {
        char symbol = top->data;
        StackFramePtr discard = top;
        top = top->link;
        delete discard;
        return symbol;
    }
}

bool Stack::empty() const {
    return (this->top == nullptr);
}

int main() {
    Stack s;
    char next, ans;

    do {
        cout << "Please enter a word\n";
        cin.get(next);

        while (next != '\n') {
            s.push(next);
            cin.get(next);
        }

        cout << "The given word in backwards is ";
        while (!s.empty())
            cout << s.pop();
        cout << endl;

        cout << "Do you want to try again?";
        cin.get(ans);
        cin.ignore(9999,'\n');
    } while ((ans != 'n') && (ans != 'N'));

    return 0;
}

*/
