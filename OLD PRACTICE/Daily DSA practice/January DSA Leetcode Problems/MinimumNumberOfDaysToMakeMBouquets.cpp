#include <bits/stdc++.h>
bool possible(vector<int> &nums, int day, int m, int k)
{
    int cnt = 0;
    int bqt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= day)
        {
            cnt++;
        }
        else
        {
            bqt += cnt / k;
            cnt = 0;
        }
    }
    bqt += cnt / k;
    if (bqt >= m)
        return true;
    return false;
}
pair<int, int> findMiniAndMaxi(vector<int> &nums)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
        mini = min(mini, nums[i]);
    }
    return {mini, maxi};
}
int roseGarden(vector<int> arr, int k, int m)
{
    // Write your code here
    long long val = m * 1ll * k * 1ll;
    if (val > arr.size())
        return -1;
    else
    {
        pair<int, int> minMax = findMiniAndMaxi(arr);
        int low = minMax.first;
        int high = minMax.second;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (possible(arr, mid, m, k))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
    return -1;
}