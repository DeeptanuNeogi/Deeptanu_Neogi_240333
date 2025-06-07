#include <iostream>
#include <string>
#include<unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashMap; 
        int maxLength = 0;
        int i = 0; 
        for (int j = 0; j < s.size(); j++) {
            char currentChar = s[j];
            if (hashMap.find(currentChar) != hashMap.end() && hashMap[currentChar] >= i) {
                i = hashMap[currentChar] + 1; 
            }
            hashMap[currentChar] = j;
            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};

int main() {
    
    Solution solution;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
