#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++)
    {
        cin >> nums[i];
    }
    int maxLen = 1;
    int i = 0;
    int maxi = INT_MIN;
    int j = 0;
    while(j<nums.size())
    {
        if(nums[j]>maxi)
        {
            maxLen = max(maxLen,j-i+1);
        }
        else
        {
            i = j;
        }
        maxi = nums[j];
        j++;
    }
    cout << maxLen;
    return 0;
}