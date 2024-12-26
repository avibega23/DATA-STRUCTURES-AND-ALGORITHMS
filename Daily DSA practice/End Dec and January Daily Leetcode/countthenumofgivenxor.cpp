
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    int xr = 0;
    unordered_map<int, int> mpp;
    mpp[xr]++;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ nums[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    solve(nums, k);
}