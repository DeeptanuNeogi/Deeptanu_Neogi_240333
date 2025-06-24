#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int factorial = 1;

        
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
            factorial *= i;
        }

        
        k--;

        string result = "";

        // Generate the permutation
        for (int i = 0; i < n; ++i) {
            factorial /= (n - i); 
            int index = k / factorial; 
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index); 
            k %= factorial; 
        }

        return result;
    }
};

int main() {
    int n, k;
    cout << "Enter the value of n (number of elements): ";
    cin >> n;
    cout << "Enter the value of k (k-th permutation): ";
    cin >> k;

    if (n <= 0 || k <= 0) {
        cout << "Invalid input. Both n and k must be positive.\n";
        return 0;
    }

    Solution solution;
    string result = solution.getPermutation(n, k);

    cout << "The " << k << "-th permutation of numbers 1 to " << n << " is: " << result << "\n";
    return 0;
}
