#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int>& A) {
    int n = A.size();
    vector<int> result(n, -1); 
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        
        while (!st.empty() && st.top() <= A[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(A[i]);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<int> result = nextGreater(A);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
