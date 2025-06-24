#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of nodes." << endl;
        return 0;
    }

    vector<Node*> nodes;
    cout << "Enter the node values: " << endl;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        nodes.push_back(newNode);
        if (i > 0) {
            nodes[i - 1]->next = newNode;
        }
    }

    Node* head = nodes[0];

    cout << "Original linked list: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = reverseList(head);

    cout << "Reversed linked list: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
