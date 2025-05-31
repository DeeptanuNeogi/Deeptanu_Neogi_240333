

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
        char c = s[i]; 
        if (c == '(' || c == '{' || c == '[') {
        st.push(c); // push to open the bracket
        } else {
        if (st.empty()) return false; 

        char top = st.top();
        if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
            st.pop(); // Pop matching opening bracket
        } else {
            return false; // Brackets don't match
        }
        }
    }
        return st.empty();
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter a string with brackets: ";
    cin >> s;

    if (solution.isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
