#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack; 

public:
    MinStack() {}

    void push(int x) {
        mainStack.push(x);

       
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) return;

        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        mainStack.pop();
    }

    int top() {
        if (mainStack.empty()) return -1; 
        return mainStack.top();
    }

    int getMin() {
        if (minStack.empty()) return -1;
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    int choice;

    cout << "Min Stack Operations:\n";
    cout << "1. Push\n2. Pop\n3. Top\n4. Get Min\n5. Exit\n";

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                minStack.push(value);
                break;
            }
            case 2:
                minStack.pop();
                cout << "Top element popped.\n";
                break;
            case 3:
                cout << "Top element: " << minStack.top() << endl;
                break;
            case 4:
                cout << "Minimum element: " << minStack.getMin() << endl;
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
