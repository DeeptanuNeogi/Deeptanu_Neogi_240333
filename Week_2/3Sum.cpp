#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
    public:
        vector<vector<int>> threeSum(vector<int>& a){
            vector<vector<int>>result;
            int n = a.size();
            sort(a.begin(),a.end()); 
            for(int i = 0; i <n-1 ; i++){
            if (i == 0 && a[i] == a[i - 1]) continue;

            int target = -a[i];
            int j = i+1;
            int k = n-1;
            while(j<k){
                if(a[j] + a[k] == target){
                
                    result.push_back({a[i], a[j], a[k]});
                    while ( a[j] == a[j + 1]) j++;
                    while ( a[k] == a[k - 1]) k--;
                    j++;
                    k--;
                } else if (a[j] + a[k] < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution sol;
    vector<vector<int>>result = sol.threeSum(a);
    if (result.empty()) {
        cout << "[]" << endl;
    }
    else {
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
}
    return 0;
}