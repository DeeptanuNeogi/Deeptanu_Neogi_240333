#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* solve(ListNode* head) {
        if (!head || !head->next) return head;

        stack<int> evenValues;
        ListNode* temp = head;
        int index = 1;

        while (temp) {
            if (index % 2 == 0) {
                evenValues.push(temp->val);
            }
            temp = temp->next;
            index++;
        }

        temp = head;
        index = 1;

        while (temp) {
            if (index % 2 == 0) {
                temp->val = evenValues.top();
                evenValues.pop();
            }
            temp = temp->next;
            index++;
        }

        return head;
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
    int n;
    cout << "Enter the number of nodes in the list: ";
    cin >> n;

    if (n <= 0) {
        cout << "The list is empty.\n";
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter the values for the list:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = createNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original List: ";
    printList(head);

    Solution solution;
    head = solution.solve(head);

    cout << "Modified List with even indices reversed: ";
    printList(head);

    return 0;
}
