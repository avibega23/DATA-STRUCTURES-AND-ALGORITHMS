#include <bits/stdc++.h>
bool helper(vector<int> &arr, int target, int i, int sum)
{
    if (i >= arr.size())
    {
        if (sum == target)
        {
            return true;
        }
        return false;
    }

    if (helper(arr, target, i + 1, sum + arr[i]) == true)
    {
        return true;
    }
    if (helper(arr, target, i + 1, sum) == true)
    {
        return true;
    }
    return false;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    return helper(a, k, 0, 0);
}
