#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int maxi = 0;
    int mini = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        maxi = max(maxi, prices[i] - mini);
    }
    return maxi;
}