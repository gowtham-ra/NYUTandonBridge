// Created by Gowtham Ra on 01/10/20.
// Practice Exam 3

/*
 1. For a nearly sorted vector of integers, insertion sort is preferred over quick sort because even in the best case
    the running time for quick sort is O(nlogn). However if the vector is nearly sorted, the inner loop of
    insertion sort will only run for the element which is unsorted and thus producing an overall run time of O(n)
    which will be better than quick sort's best case running time. ---- [Y]

 2. In the worst case, the time complexity of quick sort is O(n^2). This will happen if the pivot value
    chosen everytime is the minimum element or the maximum element of the list. If the value is minimum or maximum
    each partition of the list will reduce the total size of the list by only one thus running the partitioning
    n times instead of logn time and producing an overall time complexity of O(n^2) ---- [Y]

 3. The drawback of space efficiency is that it will be O(n) instead of O(1). This happens because during every merge
    operation in the merge sort, a new array is created for merging the sorted values and these sorted values
    from this array are copied back to the original array. Merge sort will always be O(nlogn) ---- [Y]

 4. Before using the binary search algorithm, the developer should assume that the list will be sorted, else the
    algorithm will not work. ---- [Y]

 5. BASE DERIVED BASE BASE DERIVED BASE ---- [N] (second is base

 6. When a class has a pure virtual function it becomes an abstract class.
    No, abstract class cannot be instantiated because there is a pure virtual function which doesnt have any
    definition inside the class and thus calling it using the object will lead to undefined issues.

    class Person {
    public:
        move() = 0;
    }; ---- [Y]

 7. The data and the functions that operate on these data are bundled together into a single unit called objects.
    This mechanism is called encapsulation. Encapsulation also enables hiding its information from the outside world
    (main function) by using access modifiers. ---- [Y]

 8. Constructor with two values.
    Copy constructor. ---- [Y]

 9. sort implementation - easy.

 10. Done below

 11. Ignored (HARD)

 12.



 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr) {}
};
ListNode* reverse_linked_list(ListNode* head) {
// Reverse the linked list and return the new head after reversing
    ListNode* prev, *curr, *next;
    prev = nullptr;
    curr = head;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;


}
bool is_target_in_list(ListNode* head, int target) {
// check if the linked list contains the target
    if (head != nullptr){
        ListNode* itr = head;
        while (itr != nullptr) {
            if (itr->val == target)
                return true;
            itr = itr->next;
        }
    }
    return false;
}

int find_max(ListNode* head) {
// find the largest value in the node
    if (head == nullptr) {
        cout << "The list is empty\n";
        exit(1);
    }

    int maxVal = head->val;
    ListNode* itr = head->next;

    while (itr != nullptr) {
        if (itr->val > maxVal)
            maxVal = itr->val;
        itr = itr->next;
    }
    return maxVal;
}*/

