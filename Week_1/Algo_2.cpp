
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
   
    unordered_map<int, int> freq;
    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }


    int max_visible_boxes = 0;
    for (const auto& entry : freq) {
        max_visible_boxes = max(max_visible_boxes, entry.second);
    }

    // Output the result
    cout << max_visible_boxes << endl;

    return 0;
}
