// Created by Gowtham Ra on 22/09/20.
// Interface file for a Node Class

namespace linkedListOfClasses {
    class Node {
    public:
        Node();
        Node(int value, Node* next);
        int getData() const;
        Node* getLink() const;
        void setData(int value);
        void setLink(Node* next);
    private:
        int data;
        Node* link;
    };
    typedef Node* NodePtr;
}
