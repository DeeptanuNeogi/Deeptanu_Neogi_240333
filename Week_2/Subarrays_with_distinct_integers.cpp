#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function definitions
int subarray_having_elements_less(vector<int> arr, int B) {
    int start = 0, end = 0;
    int n = arr.size();
    map<int, int> mp;
    int ans = 0;
    while (end < n) {
        mp[arr[end]]++;
        while (mp.size() > B) {
            mp[arr[start]]--;
            if (mp[arr[start]] == 0)
                mp.erase(arr[start]);
            start++;
        }
        ans += end - start + 1;
        end++;
    }
    return ans;
}

int solve(vector<int> &arr, int B) {
    return subarray_having_elements_less(arr, B) - subarray_having_elements_less(arr, B - 1);
}

int main() {
    int n, B;
    cin >> n >> B;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Number of subarrays with exactly " << B << " different integers: " 
         << solve(arr, B) << endl;

    return 0;
}
