#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kthsmallest(vector<int>& A, int B) {

        sort(A.begin(), A.end());

        return A[B - 1];
    }
};

int main() {
    int n, k;
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

    cout << "Enter the value of k (1-based index): ";
    cin >> k;

    if (k <= 0 || k > n) {
        cout << "Invalid value of k.\n";
        return 0;
    }

    Solution solution;
    int kthSmallest = solution.kthsmallest(arr, k);

    cout << "The " << k << "-th smallest element in the array is: " << kthSmallest << "\n";

    return 0;
}
