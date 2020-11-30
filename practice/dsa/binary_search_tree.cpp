// Created by Gowtham Ra on 27/09/20.
// Program to implement binary search tree

#include <iostream>
#include <list>
#include <utility>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class BSTNode {
public:
    BSTNode() : data(T()), parent(nullptr), left(nullptr), right(nullptr) {}

    BSTNode(T theData = T(), BSTNode<T>* parentPtr = nullptr,
            BSTNode<T>* leftPtr = nullptr, BSTNode<T>* rightPtr = nullptr ) :
            data(theData), parent(parentPtr), left(leftPtr), right(rightPtr) {}

    friend class BinarySearchTree<T>;
    int getSize() const; //Gets the count of nodes in the tree with given node as root.

private:
    T data;
    BSTNode<T>* parent;
    BSTNode<T>* left;
    BSTNode<T>* right;
};

template<class T>
int BSTNode<T>::getSize() const {
    int count = 1; //Counting the current node
    if (left != nullptr)
        count += left->getSize();
    if (right != nullptr)
        count += right->getSize();
    return count;
}

/*
 * PENDING
 * 1. Make a remove function for data given as param and that node has to be deleted.
 * 2. makeEmpty()
 * 3. Big 3
 * */

template <class T>
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {};
    BinarySearchTree(BSTNode<T>* theTree = nullptr) : root(theTree) {}

    //Big 3
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<T>& rhs);

    bool contains(BSTNode<T>* node, const T& theData) const;
    void insertRecursive(BSTNode<T>*& node, T& theData);
    void insertIterative(T& theData);
    void remove1(BSTNode<T>*& node); //My method
    void remove2(BSTNode<T>*& node); //NYU bridge module method
    void remove3(BSTNode<T>*& node); //DSA book method
    void makeEmpty(BSTNode<T>*& node);
    BSTNode<T>* clone(BSTNode<T>* node) const;
    void printInOrder(BSTNode<T>* node);
    void printPreOrder(BSTNode<T>* node);
    void printPostOrder(BSTNode<T>* node);
    void printLevelOrder();
    int findMin(BSTNode<T>* node) const;
    int findMax(BSTNode<T>* node) const;
    int findHeight(BSTNode<T>*& node) const;
    bool isBinarySearchTree(BSTNode<T>*& node) const;
    BSTNode<T>* getSuccessor(BSTNode<T>*& node, T theData) const;
    list<int> sortedList(BSTNode<int>* node, list<int>& list);

private:
    BSTNode<T>* root;
};

template<class T>
bool BinarySearchTree<T>::contains(BSTNode<T>* node, const T& theData) const {
    //Order of arrangements is important with null first, since if node is null
    //we cannot access its members and the least likely case should be the last.
    if (node == nullptr)
        return false;
    else if (theData < node->data)
        return contains(node->left);
    else if (theData > node->data)
        return contains(node->right);
    else
        return true;
}

template<class T>
void BinarySearchTree<T>::insertRecursive(BSTNode<T>*& node, T& theData) {
    if (node == nullptr)
        node = new BSTNode<T>(theData);
    else if (theData < node->data)
        insertRecursive(node->left, theData);
    else if (theData > node->data)
        insertRecursive(node->right, theData);
    else
        ; //If duplicate do nothing
}

//Inserting a node into a BST iterative
template<class T>
void BinarySearchTree<T>::insertIterative(T& theData) {
    if (this->root == nullptr) {
        root = new BSTNode<T>(theData);
        return;
    }

    BSTNode<T>* temp = this->root;
    BSTNode<T>* prev;
    while (temp != nullptr){
        prev = temp;
        if (theData < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (theData < prev->data)
        prev->left = new BSTNode<T>(theData,prev);
    else
        prev->right = new BSTNode<T>(theData,prev);
}

template<class T>
void BinarySearchTree<T>::printInOrder(BSTNode<T> *node) {
    if (node != nullptr) {
        printInOrder(node->left);
        cout << node->data << ", ";
        printInOrder(node->right);
    }
}

template<class T>
void BinarySearchTree<T>::printPreOrder(BSTNode<T> *node) {
    if (node != nullptr) {
        cout << node->data << ", ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

template<class T>
void BinarySearchTree<T>::printPostOrder(BSTNode<T> *node) {
    if (node != nullptr) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << ", ";
    }
}

//Needs a queue class
template<class T>
void BinarySearchTree<T>::printLevelOrder() {
    Queue<BSTNode<T>*> q;
    q.push(this->root);
    while (!q.empty()) {
        BSTNode<T>* temp = q.front();
        q.pop();
        cout << temp->data << ", ";
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

//Removal - My method
template<class T>
void BinarySearchTree<T>::remove1(BSTNode<T> *&node) {
    if (node == nullptr)
        return;

    BSTNode<T>* parent = node->parent;
    if ((node->left == nullptr) && (node->right == nullptr)) { //Node has no child
        if (parent == nullptr)
            root = nullptr;
        else if (parent->left == node)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete node;
    }
    else if (node->left == nullptr) { //Node has a right child
        if (parent == nullptr) {
            root = node->right;
            node->right->parent = nullptr;
        }
        else if (parent->left == node) {
            parent->left = node->right;
            node->right->parent = parent;
        }
        else {
            parent->right = node->right;
            node->right->parent = parent;
        }
        delete node;
    }
    else if (node->right == nullptr) { //Node has a left child
        if (parent == nullptr) {
            root = node->left;
            node->left->parent = nullptr;
        }
        else if (parent->left == node) {
            parent->left = node->left;
            node->left->parent = parent;
        }
        else {
            parent->right = node->left;
            node->left->parent = parent;
        }
        delete node;
    }
    else { //Node has two children, so promoting max of left
        BSTNode<T>* maxOfLeft = node->left;
        while (maxOfLeft->right != nullptr)
            maxOfLeft = maxOfLeft->right;
        node->data = maxOfLeft->data;
        remove1(maxOfLeft);
    }
}

//Removal method given in NYU Bridge module
template<class T>
void BinarySearchTree<T>::remove2(BSTNode<T> *&node) {
    BSTNode<T>* parent = node->parent;
    if ((node->left == nullptr) && (node->right == nullptr)) { //Node has no child
        if (parent == nullptr)
            root = nullptr;
        else if (parent->left == node)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete node;
    }
    else if (node->left == nullptr) { //Node has a right child
        BSTNode<T>* toDelete = node->right;
        node->data = toDelete->data;

        node->left = toDelete->left;
        if (toDelete->left != nullptr)
            toDelete->left->parent = node;

        node->right = toDelete->right;
        if (toDelete->right != nullptr)
            toDelete->right->parent = node;

        delete toDelete;
    }
    else if (node->right == nullptr) { // Node has a left child
        BSTNode<T>* toDelete = node->left;
        node->data = toDelete->data;

        node->left = toDelete->left;
        if (toDelete->left != nullptr)
            toDelete->left->parent = node;

        node->right = toDelete->right;
        if (toDelete->right != nullptr)
            toDelete->right->parent = node;

        delete toDelete;
    }
    else { //Node has two children, so promoting min of right
        BSTNode<T>* minOfRight = node->right;
        while (minOfRight->left != nullptr)
            minOfRight = minOfRight->left;
        node->data = minOfRight->data;
        remove2(minOfRight);
    }
}

//DSA Book Method (easiest of all)
template<class T>
void BinarySearchTree<T>::remove3(BSTNode<T> *&node) {
    if (node == nullptr)
        return;

    //Two children
    if ((node->left != nullptr) && (node->right != nullptr)) {
        BSTNode<T>* minOfRight = findMin(node->right);
        node->data = minOfRight->data;
        remove3(minOfRight);
    }
    //One or zero children
    else {
        BSTNode<T>* deleteNode = node;
        node = (node->left != nullptr) ? node->left : node->right;
        delete deleteNode;
    }
}

template<class T>
int BinarySearchTree<T>::findMin(BSTNode<T>* node) const {
    if (node == nullptr) {
        cout << "The tree is empty\n";
        exit(1);
    }
    if (node->left == nullptr)
        return node->data;

    return findMin(node->left);;
}

template<class T>
int BinarySearchTree<T>::findMax(BSTNode<T> *node) const {
    if (node == nullptr) {
        cout << "The tree is empty\n";
        exit(1);
    }

    if (node->right == nullptr)
        return node->data;

    return findMax(node->right);;
}

//TC = O(n)
template<class T>
int BinarySearchTree<T>::findHeight(BSTNode<T> *&node) const {
    int height;

    if (node == nullptr)
        return -1;

    height = max(findHeight(node->left),findHeight(node->right)) + 1;

    return height;
}

//Copied from G4G, unable to find on your own
template<class T>
bool BinarySearchTree<T>::isBinarySearchTree(BSTNode<T> *&node) const {
    if (node == nullptr)
        return true;

    if (node->left != nullptr && findMax(node->left) > node->data)
        return false;

    if (node->right != nullptr && findMin(node->right) < node->data)
        return false;

    if (!isBinarySearchTree(node->left) || !isBinarySearchTree(node->right))
        return false;

    return true;
}

//Revisit
template<class T>
BSTNode<T> *BinarySearchTree<T>::getSuccessor(BSTNode<T> *&node, T theData) const {
    BSTNode<T>* current = contains(node, theData);

    //Case 1: Node has right sub tree
    if (current->right != nullptr)
        return findMin(current->right);
    else { //Case 2: Node has no right sub tree
        BSTNode<T>* successor = nullptr;
        BSTNode<T>* ancestor = node;

        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    makeEmpty(this->root);
}

template<class T>
void BinarySearchTree<T>::makeEmpty(BSTNode<T> *&node) {
    if (node!= nullptr) {
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
    }
    node = nullptr;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &rhs) {
    this->root = nullptr;
    root = clone(rhs.root);
}

template<class T>
BSTNode<T> *BinarySearchTree<T>::clone(BSTNode<T> *node) const {
    if (node == nullptr)
        return nullptr;
    else
        return new BSTNode<T>(node->data, nullptr, clone(node->left), clone(node->right));
}

/*
 SOME TIPS:
 1. A better way to design BST class is to have public functions for all above and also private functions.
 Ex: For insert() function, public function will have only data as param and private insert function will
 have both data and node as param to support recursive definition (so that the user no need to include the
 root node as param everytime (which is only an impl requirement that doesn't concern the user).

 2. Give big 3 (copy cons, operator=, destructors) as well

 3. Make the node data as of type comparable than T to enable comparisons (<, >) without overloading them.

 4. include parent ptr member in node only if it is required (else it will complicate all other functions)
*/


template<>
list<int> BinarySearchTree<int>::sortedList(BSTNode<int>* node, list<int>& list) {
    if (node != nullptr) {
        sortedList(node->left, list);
        list.push_back(node->data);
        sortedList(node->right, list);
    }
    return list;
}

