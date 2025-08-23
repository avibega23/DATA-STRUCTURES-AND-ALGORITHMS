#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>nums(2*n);
        for(int i = 0;i<2*n;i++)
        {
            cin >> nums[i];
        }
        sort(nums.begin(),nums.end());
        int sum = nums[n]-nums[n-1];
        cout << sum << endl;
    }

    

    return 0;
}