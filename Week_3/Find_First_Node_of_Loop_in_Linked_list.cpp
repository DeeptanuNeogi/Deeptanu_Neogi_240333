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

Node* findFirstNode(Node* head) {
    unordered_set<Node*> st;
    Node* currNode = head;

    while (currNode != nullptr) {
        if (st.find(currNode) != st.end()) {
            return currNode;
        }
        st.insert(currNode);
        currNode = currNode->next;
    }

    return nullptr;
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

    int loopPos;
    cout << "Enter the position (0-based) of the node to create a loop, or -1 for no loop: ";
    cin >> loopPos;

    if (loopPos >= 0 && loopPos < n) {
        nodes[n - 1]->next = nodes[loopPos];
    }

    Node* loopNode = findFirstNode(head);

    if (loopNode)
        cout << "The first node of the loop is: " << loopNode->data << endl;
    else
        cout << "No loop detected in the linked list." << endl;

    return 0;
}
