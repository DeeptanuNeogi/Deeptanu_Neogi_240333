/*Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.
An input string is valid if:

         1. Open brackets must be closed by the same type of brackets.
         2. Open brackets must be closed in the correct order.

Examples :

Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.
Input: s = "[()()]{}"
Output: true
Explanation: All the brackets are well-formed.
Input: s = "([]"
Output: False
Explanation: The expression is not balanced as there is a missing ')' at the end.
Input: s = "([{]})"
Output: False
Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.
Constraints:
1 ≤ s.size() ≤ 106
s[i] ∈ {'{', '}', '(', ')', '[', ']'}*/


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
