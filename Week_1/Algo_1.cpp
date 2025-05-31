
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, x, i;
    cin >> n 
    cin >> x;
    vector<int> arr(n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> brr;
    brr[0] = 1;
    int currentSum = 0;
    int count = 0;

    for (i = 0; i < n; i++) {
        currentSum += arr[i];
        if (brr.find(currentSum - x) != brr.end()) {
            count += brr[currentSum - x];
        }
        brr[currentSum]++;
    }

    cout << count << endl;
    return 0;
}
