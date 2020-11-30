// Created by Gowtham Ra on 29/09/20.
// Program to implement AVL BST

#include <iostream>
using namespace std;

const int ALLOWED_IMBALANCE = 1;

template <typename Comparable>
class AVLNode {
public:
    AVLNode(const Comparable& newData, AVLNode<Comparable>* leftPtr = nullptr,
            AVLNode<Comparable>* rightPtr = nullptr, int ht = 0) : data(newData), left(leftPtr),
            right(rightPtr), height(ht) {}

    int getHeight(AVLNode<Comparable>* node) const {return node == nullptr ? -1 : node->height;}

    void insert(const Comparable& theData, AVLNode<Comparable>*& node);
    void balance(AVLNode<Comparable>*& node);
    void rotateWithLeftChild(AVLNode<Comparable>*& k2);
    void rotateWithRightChild(AVLNode<Comparable>*& k1);
    void doubleWithLeftChild(AVLNode<Comparable>*& k3);
    void doubleWithRightChild(AVLNode<Comparable>*& k1);
    void remove(Comparable theData, AVLNode<Comparable>*& node);

private:
    Comparable data;
    AVLNode<Comparable>* left;
    AVLNode<Comparable>* right;
    int height;
};

template<typename Comparable>
void AVLNode<Comparable>::insert(const Comparable &theData, AVLNode<Comparable> *&node) {
    if (node == nullptr)
        node = new AVLNode<Comparable>(theData);
    else if(theData < node->data)
        insert(theData, node->left);
    else if (theData > node->data)
        insert(theData, node->right);

    balance(node);
}

template<typename Comparable>
void AVLNode<Comparable>::balance(AVLNode<Comparable> *&node) {
    if (node == nullptr)
        return;

    if (getHeight(node->left) - getHeight(node->right) > ALLOWED_IMBALANCE) {
        //= to accommodate node deletion
        if (getHeight(node->left->left) >= getHeight(node->left->right))
            rotateWithLeftChild(node);
        else
            doubleWithLeftChild(node);
    }
    else if (getHeight(node->right) - getHeight(node->left) > ALLOWED_IMBALANCE) {
        //= to accommodate node deletion
        if (getHeight(node->right->right) >= getHeight(node->right->left))
            rotateWithRightChild(node);
        else
            doubleWithRightChild(node);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

template<typename Comparable>
void AVLNode<Comparable>::rotateWithLeftChild(AVLNode<Comparable>*& k2) {
    AVLNode<Comparable>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
    k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
    k2 = k1;
}

template<typename Comparable>
void AVLNode<Comparable>::rotateWithRightChild(AVLNode<Comparable> *&k1) {
    AVLNode<Comparable>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(getHeight(k1->left), getHeight(k2->right)) + 1;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
    k1 = k2;
}

template<typename Comparable>
void AVLNode<Comparable>::doubleWithLeftChild(AVLNode<Comparable> *&k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template<typename Comparable>
void AVLNode<Comparable>::doubleWithRightChild(AVLNode<Comparable> *&k1) {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

template<typename Comparable>
void AVLNode<Comparable>::remove(Comparable theData, AVLNode<Comparable>*& node) {
    if (node == nullptr)
        return;

    if (theData < node->data)
        remove(node->left);
    else if (theData > node->data)
        remove(node->right);
    else if (node->left != nullptr && node->right != nullptr) { //Case when 2 there are 2 children
        AVLNode<Comparable>* minOfRight = findMin(node->right);
        node->data = minOfRight->data;
        remove(minOfRight);
    }
    else { //Case when there are 1 or no child
        AVLNode<Comparable>* discard = node;
        node = (node->left != nullptr) ? node->left : node->right;
        delete discard;
    }
    balance(node); //Balancing is enough for deletion as well
}

