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

    int cnt = 0;
    int mini = INT_MAX;
    int minDex = -1;
    int maxIndex = -1;
    int maxi = INT_MIN;

    for(int i = 0;i<nums.size();i++)
    {
        
        if(nums[i]>maxi)
        {
            maxi = nums[i];
            maxIndex = i;
        }

        if(nums[i]<=mini)
        {
            mini = nums[i];
            minDex = i;
        }
    }
    cnt += maxIndex + (nums.size()-minDex-1);
    cnt -= (maxIndex > minDex) ? 1 : 0;
    cout << cnt;
    return 0;
}