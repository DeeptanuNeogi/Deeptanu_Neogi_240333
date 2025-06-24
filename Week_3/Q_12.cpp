#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string A) {
        if (A.empty()) return {};

        vector<string> result;
        string current;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(0, A, current, result, mapping);
        return result;
    }

private:
    void backtrack(int index, const string& A, string& current, vector<string>& result, const vector<string>& mapping) {
        if (index == A.size()) {
            result.push_back(current);
            return;
        }

        int digit = A[index] - '0';
        if (digit < 0 || digit > 9 || mapping[digit].empty()) return;

        for (char letter : mapping[digit]) {
            current.push_back(letter);
            backtrack(index + 1, A, current, result, mapping);
            current.pop_back(); 
        }
    }
};

int main() {
    string input;
    cout << "Enter the digit string: ";
    cin >> input;

    Solution solution;
    vector<string> result = solution.letterCombinations(input);

    cout << "Possible letter combinations are:\n";
    for (const string& combination : result) {
        cout << combination << "\n";
    }

    return 0;
}
