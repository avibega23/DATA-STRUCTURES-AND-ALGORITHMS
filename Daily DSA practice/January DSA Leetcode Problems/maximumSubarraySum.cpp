#include <bits/stdc++.h>
long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long maxi = INT_MIN;
    long long sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        maxi = max(maxi, sum);
    }
    return maxi;
}