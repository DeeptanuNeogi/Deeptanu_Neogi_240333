
#include <iostream>
#include <vector>
using namespace std;
const int max_beauty = 10000;

int main() {
	int T,N;
    cin >> T; // Number of test cases
    cin >> N; // Number of rods
    while (T--) {
        
        vector<int> lengths(N), beauties(N);
        vector<int> buckets(max_beauty + 1, 0);

        for (int i = 0; i < N; i++) {
            cin >> lengths[i]; // Lengths of rods
        }

        for (int i = 0; i < N; i++) {
            cin >> beauties[i]; // Beauties of rods
            buckets[beauties[i]] += lengths[i]; 
        }

        int maxBeauty = 0, currentPosition = 0;

        for (int b = max_beauty; b >= 1; b--) {
            if (buckets[b] > 0) {
                maxBeauty += currentPosition * b; 
                currentPosition += buckets[b];   
            }
        }

        cout << maxBeauty ;
    }
    
    return 0;

}
