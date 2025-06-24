#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        vector<vector<int>> result;
        vector<int> current;
        sort(A.begin(), A.end()); 
        generateSubsets(0, A, current, result);
        return result;
    }

private:
    void generateSubsets(int index, vector<int>& A, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = index; i < A.size(); ++i) {
            if (i > index && A[i] == A[i - 1]) continue; 

            current.push_back(A[i]); 
            generateSubsets(i + 1, A, current, result); 
            current.pop_back(); 
        }
    }
};

void printSubsets(const vector<vector<int>>& subsets) {
    cout << "[\n";
    for (const auto& subset : subsets) {
        cout << "  [";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "The array is empty.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution solution;
    vector<vector<int>> result = solution.subsetsWithDup(arr);

    cout << "Unique subsets are:\n";
    printSubsets(result);

    return 0;
}
