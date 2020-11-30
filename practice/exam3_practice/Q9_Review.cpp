
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

template <typename T>
list<T> lessEqVals(BSTNode<T>* root, T value) {
    list<T> list;

    BSTNode<T>* valNode = findValNode(root, value);

    addValues(valNode, list);
    return list;
}

template <typename T>
BSTNode<T>* findValNode(BSTNode<T>* node, T value) {
    if (node == nullptr) {
        cout << "Value not found\n";
        exit(1);
    }

    if (node->data == value) {
        return node;
    }
    else if (node->data > value) {
        return findValNode(node->left, value);
    }
    else
        return findValNode(node->right, value);
}

template <typename T>
void addValues(BSTNode<T>* node, list<T>& list) {
    if (node != nullptr) {
        addValues(node->left, list);
        list.push_back(node->data);
        addValues(node->right, list);
    }
}