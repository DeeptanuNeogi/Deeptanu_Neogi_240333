/*Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.
Examples :

Input: s = "((()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".
Input: s = ")()())"
Output: 4
Explanation: The longest valid parenthesis substring is "()()".
Input: s = "())()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".
Constraints:
1 ≤ s.size() ≤ 106  
s consists of '(' and ')' only*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
  public:
    int maxLength(string& s) {
        
       stack<pair<char,int>>st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({'(',i});
            }
            else{
                if (!st.empty() && st.top().first == '(') {
                int matchingStart = st.top().second;
                st.pop();

                if (!st.empty()) {
                ans = max(ans, i - st.top().second);
                } else {
                ans = max(ans, i - matchingStart + 1);
                  }
                }

                else
                st.push({')',i});
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    string s;
    cout << "Enter the string : ";
    cin >> s;

    int result = solution.maxLength(s);
    cout << "The length of the longest valid parentheses substring is: " << result << endl;

    return 0;
}