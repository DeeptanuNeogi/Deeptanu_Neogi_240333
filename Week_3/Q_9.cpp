#include <iostream>
using namespace std;

class Solution {
public:
    int pow(int x, int n, int d) {
        if (d == 1) return 0; 

        long long base = x % d; 
        long long result = 1;

        if (base < 0) {
            base += d;
        }

        while (n > 0) {

            if (n % 2 == 1) {
                result = (result * base) % d;
            }


            base = (base * base) % d;

            n /= 2;
        }

        return static_cast<int>((result + d) % d); 
    }
};

int main() {
    int x, n, d;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;
    cout << "Enter modulus (d): ";
    cin >> d;

    Solution solution;
    int result = solution.pow(x, n, d);

    cout << "The result of (" << x << "^" << n << ") % " << d << " is: " << result << "\n";
    return 0;
}
