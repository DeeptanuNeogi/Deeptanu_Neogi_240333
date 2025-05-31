
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        vector<int> even_group, odd_group;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0)
                even_group.push_back(arr[i]);
            else
                odd_group.push_back(arr[i]);
        }

        
        vector<int> sorted_a = arr;
        sort(sorted_a.begin(), sorted_a.end());
        sort(even_group.begin(), even_group.end());
        sort(odd_group.begin(), odd_group.end());

        
        bool isPossible = true;
        int even_idx = 0, odd_idx = 0;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                if (sorted_a[i] != even_group[even_idx++]) {
                    isPossible = false;
                    break;
                }
            } else {
                if (sorted_a[i] != odd_group[odd_idx++]) {
                    isPossible = false;
                    break;
                }
            }
        }

        // Output result
        if(isPossible){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
