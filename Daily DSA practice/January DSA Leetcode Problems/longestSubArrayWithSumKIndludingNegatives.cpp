#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &arr, int k)
{
    // Write your code here
    int sum = 0;
    int maxLen = 0;
    map<int, int> preSumMap;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = sum - k;

        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}