#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubarrayWithSumK(vector<int>& a, long long k) {
    int n = a.size();
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0; 
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength; 
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = longestSubarrayWithSumK(a, k);
    cout  << result << endl;
    return 0;
}
