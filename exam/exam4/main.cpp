#include <iostream>
#include <string.h>
using namespace std;



template<class T>
class ExpressionTree;
template<class T>
class ExpressionTreeNode;
class Operand;
class Operator;

template<class T>
class ExpressionTree {
public:
    ExpressionTree(){}
    double getValue(ExpressionTreeNode<T>* node);

private:
    ExpressionTreeNode<T>* root;
};

template<class T>
double ExpressionTree<T>::getValue(ExpressionTreeNode<T>* node) {
    if (node != nullptr) {
        return node->getValue();
    }
}

template<class T>
class ExpressionTreeNode {
public:
    ExpressionTreeNode();
    ExpressionTreeNode(T theData, ExpressionTreeNode<T>* leftPtr = nullptr,
                       ExpressionTreeNode<T>* rightPtr = nullptr) : data(theData), left(leftPtr), right(rightPtr) {}
    virtual T getValue() = 0;
    T getData() const {return data;}

protected:
    T data;
    ExpressionTreeNode<T>* left;
    ExpressionTreeNode<T>* right;
public:
    ExpressionTreeNode<T> *getLeft() const {
        return left;
    }

    ExpressionTreeNode<T> *getRight() const {
        return right;
    }
};


class Operand : public ExpressionTreeNode<double>{
public:
    Operand() : ExpressionTreeNode(){};
    Operand(double value) : ExpressionTreeNode(value){};
    virtual double getValue() const;
};

double Operand::getValue() const {
    return this->data;
}


class Operator : public ExpressionTreeNode<char> {
public:
    Operator() : ExpressionTreeNode(){};
    Operator(char value) : ExpressionTreeNode(value){};
    virtual double getValue(ExpressionTreeNode* nodePtr);
    //virtual string getType() { return "OPR";}
};

//CHECK ONCE
double Operator::getValue(ExpressionTreeNode* nodePtr)  {

    if (nodePtr!= nullptr) {
        double value1;
        double value2;

        value1 = getValue(nodePtr->getLeft());
        value2 = getValue(nodePtr->getRight());

        if (nodePtr->getData() == '+' || nodePtr->getData() == '*') {
            double result = 0;

            switch (this->data) {
                case '+':
                    result = value1 + value2;
                    break;
                case '*':
                    result = value1 * value2;
                    break;
            }
            return result;
        }
        else {
            return nodePtr->getValue();
        }
    }
}

int main() {
    return 0;
}
