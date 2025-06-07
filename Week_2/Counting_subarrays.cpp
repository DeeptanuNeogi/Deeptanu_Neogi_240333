#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    int count = 0;
    int sum = 0;
    for (int i = 0, j = 0; j < n; j++) {
        sum += A[j];
        while (sum >= B) {
            sum -= A[i];
            i++;
        }
        count += (j - i + 1);
    }
    return count;
}

int main() {
    int n, B;
    cin >> n >> B;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "Number of subarrays with sum less than " << B << ": " 
         << solve(A, B) << endl;

    return 0;
}
