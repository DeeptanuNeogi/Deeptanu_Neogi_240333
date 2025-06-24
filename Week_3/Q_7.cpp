#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCount(const vector<int>& A, int B) {
        int first = findFirstOccurrence(A, B);
        if (first == -1) return 0; 

        int last = findLastOccurrence(A, B);
        return last - first + 1;
    }

private:

    int findFirstOccurrence(const vector<int>& A, int B) {
        int low = 0, high = A.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == B) {
                result = mid;
                high = mid - 1; // Search on the left
            } else if (A[mid] > B) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

    int findLastOccurrence(const vector<int>& A, int B) {
        int low = 0, high = A.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == B) {
                result = mid;
                low = mid + 1; 
            } else if (A[mid] > B) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "The array is empty.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter the sorted array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the element to count occurrences of: ";
    cin >> target;

    Solution solution;
    int count = solution.findCount(arr, target);

    if (count > 0) {
        cout << "The element " << target << " occurs " << count << " times in the array.\n";
    } else {
        cout << "The element " << target << " is not present in the array.\n";
    }

    return 0;
}
