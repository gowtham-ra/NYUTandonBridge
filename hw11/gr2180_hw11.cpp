/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions. 
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>


using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }
    void balance(RBTNode<T> *&point, RBTNode<T> *parent);

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;
    // TODO: ADD ROTATION CODE HERE
    grandparent->left = parent->right;
    parent->right = grandparent;
    parent->parent = grandparent->parent;
    grandparent->parent = parent;

    if (grandparent->left != nullptr)
        grandparent->left->parent = grandparent;

    if (parent->parent == nullptr)
        this->root = parent;
    else if (parent->parent->left == grandparent)
        parent->parent->left = parent;
    else
        parent->parent->right = parent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
    // TODO: ADD ROTATION CODE HERE
    grandparent->right = parent->left;
    parent->left = grandparent;
    parent->parent = grandparent->parent;
    grandparent->parent = parent;

    if (grandparent->right != nullptr)
        grandparent->right->parent = grandparent;
    if (parent->parent == nullptr)
        this->root = parent;
    else if (parent->parent->left == grandparent)
        parent->parent->left = parent;
    else
        parent->parent->right = parent;
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
        // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        // TODO: ADD RBT RULES HERE
        balance(point, parent);
    } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}
template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

template<class T>
void RBT<T>::balance(RBTNode<T> *&point, RBTNode<T> *parent) {
    //If the given node is the root node, set the color to black
    if (parent == nullptr) {
        swapColor(point);
        return;
    }
    //If the parent is black, balance is not required
    else if (parent->color == BLACK)
        return;
    //If the parent is red, balance is required
    else {
        RBTNode<T>* grandParent = parent->parent;
        RBTNode<T>* uncle;

        if (grandParent->left == parent)
            uncle = grandParent->right;
        else
            uncle = grandParent->left;

        //Case 1: If the uncle node is red, swap the colors and balance the upper nodes.
        if (uncle != nullptr && uncle->color == RED) {
            swapColor(parent);
            swapColor(uncle);
            swapColor(grandParent);
            balance(grandParent, grandParent->parent);
        }
        //Case 2: Uncle node is black or null
        else {
            //Case 2.1: New node is left-left (outwards)
            if (grandParent->left == parent && parent->left == point) {
                singleCR(grandParent);
                swapColor(grandParent);
                swapColor(grandParent->parent);
            }
            //Case 2.2: New node is right-right (outwards)
            else if (grandParent->right == parent && parent->right == point) {
                singleCCR(grandParent);
                swapColor(grandParent);
                swapColor(grandParent->parent);
            }
            //Case 2.3: New node is left-right (inwards)
            else if (grandParent->left == parent && parent->right == point) {
                doubleCR(grandParent);
                swapColor(grandParent);
                swapColor(grandParent->parent);
            }
            //Case 2.4: New node is right-left (inwards)
            else {
                doubleCCR(grandParent);
                swapColor(grandParent);
                swapColor(grandParent->parent);
            }
        }
    }
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}