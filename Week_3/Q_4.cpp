#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        return a;
    }
};


ListNode* createNode(int val) {
    return new ListNode(val);
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Input the linked lists
    int n1, n2, intersectVal;
    cout << "Enter the number of nodes in List A: ";
    cin >> n1;
    cout << "Enter the number of nodes in List B: ";
    cin >> n2;

    ListNode* headA = nullptr;
    ListNode* headB = nullptr;
    ListNode* tailA = nullptr;
    ListNode* tailB = nullptr;

    cout << "Enter values for List A:\n";
    for (int i = 0; i < n1; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = createNode(val);
        if (!headA) {
            headA = newNode;
            tailA = newNode;
        } else {
            tailA->next = newNode;
            tailA = newNode;
        }
    }

    cout << "Enter values for List B:\n";
    for (int i = 0; i < n2; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = createNode(val);
        if (!headB) {
            headB = newNode;
            tailB = newNode;
        } else {
            tailB->next = newNode;
            tailB = newNode;
        }
    }

    cout << "Enter the intersection value (or -1 for no intersection): ";
    cin >> intersectVal;

    if (intersectVal != -1) {
        ListNode* temp = headA;
        while (temp && temp->val != intersectVal) {
            temp = temp->next;
        }
        if (temp) {
            tailB->next = temp; 
        }
    }

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    Solution solution;
    ListNode* intersection = solution.getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "The intersection node value is: " << intersection->val << "\n";
    } else {
        cout << "No intersection.\n";
    }

    return 0;
}
