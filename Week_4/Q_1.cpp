#include <iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
           
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            } else {
                
                st.push(stoi(token));
            }
        }

      
        return st.top();
    }
};

int main() {
    Solution solution;
    vector<string> tokens;
    int n;

    cout << "Enter the number of tokens in the expression: ";
    cin >> n;

    cout << "Enter the tokens (numbers or operators): " << endl;
    for (int i = 0; i < n; ++i) {
        string token;
        cin >> token;
        tokens.push_back(token);
    }

    int result = solution.evalRPN(tokens);
    cout << "The result of the expression is: " << result << endl;

    return 0;
}
