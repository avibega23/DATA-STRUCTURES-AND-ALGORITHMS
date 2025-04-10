#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0;i<nums.size();i++)
    {
        cin >> nums[i];
        break;
    }
    string ans = "EASY";
    for(auto it:nums)
    {
        if(it == 1) ans = "HARD";
        break;
    }
    cout << ans;
    return 0;
}