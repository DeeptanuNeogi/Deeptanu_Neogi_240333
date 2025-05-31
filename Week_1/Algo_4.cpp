/*AquaMoon has N friends. They stand in a row from left to right, and the i-th friend from the left wears a T-shirt with a number ai
written on it. Each friend has a direction (left or right). In the beginning, the direction of each friend is right.

AquaMoon can make some operations on friends. On each operation, AquaMoon can choose two adjacent friends and swap their positions. After each operation, the direction of both chosen friends will also be flipped: left to right and vice versa.

AquaMoon hopes that after some operations, the numbers written on the T-shirt of N
friends in the row, read from left to right, become non-decreasing. Also she wants, that all friends will have a direction of right at the end. Please find if it is possible.

Input
The input consists of multiple test cases. The first line contains a single integer T(1≤t≤50) — the number of test cases.

The first line of each test case contains a single integer N (1≤n≤105) — the number of Aquamoon's friends.

The second line contains N integers a1,a2,…,an (1≤ai≤105) — the numbers, written on the T-shirts.

It is guaranteed that the sum of N for all test cases does not exceed 105.
Output
For each test case, if there exists a possible sequence of operations, print "YES" (without quotes); otherwise, print "NO" (without quotes).

You can print each letter in any case (upper or lower).*/
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
