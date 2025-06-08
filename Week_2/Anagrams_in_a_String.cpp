#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> pCount, sCount;
        for (int i = 0; i < p.size(); i++) {
            pCount[s[i]]++;
        }

        int n = p.size();

        for (int i = 0; i < s.size(); i++) {
            sCount[s[i]]++;
            if (i >= n) {
                char charToRemove = s[i - n];
                sCount[charToRemove]--;
                if (sCount[charToRemove] == 0) {
                    sCount.erase(charToRemove);
                }
            }
            if (sCount == pCount) {
                result.push_back(i - n + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s, p;

    cout << "Enter the string s: ";
    cin >> s;

    cout << "Enter the string p: ";
    cin >> p;

    vector<int> result = solution.findAnagrams(s, p);

    cout << "Starting indices of anagrams: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
