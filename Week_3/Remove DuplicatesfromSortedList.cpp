#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* A) {
        ListNode* current = A;

        while (current != NULL && current->next != NULL) {
            if (current->val == current->next->val) {
                
                current->next = current->next->next;
            } else {
                
                current = current->next;
            }
        }

        return A;
    }
};

ListNode* createListFromInput() {
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    if (n == 0) return NULL;

    cout << "Enter the elements of the list: ";
    int val;
    cin >> val;

    ListNode* head = new ListNode(val);
    ListNode* current = head;

    for (int i = 1; i < n; ++i) {
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = createListFromInput();

    cout << "Original List: ";
    printList(head);

    Solution solution;
    head = solution.deleteDuplicates(head);

    cout << "List After Removing Duplicates: ";
    printList(head);

    return 0;
}
