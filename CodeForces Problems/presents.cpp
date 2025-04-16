#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0;i<nums.size();i++)
    {
        cin >> nums[i];
    }
    vector<int>ans(n);
    for(int i = 0;i<nums.size();i++)
    {
        ans[nums[i]-1] = i+1;
    }
    for(auto it:ans)
    {
        cout << it << " ";
    }
    

    return 0;
}