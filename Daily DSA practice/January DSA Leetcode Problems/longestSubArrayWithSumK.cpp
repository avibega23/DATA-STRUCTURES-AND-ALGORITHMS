#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {

    // Write your code here
    int n = a.size();
    int i = 0;
    int j = 0;
    long long sum = a[0];
    int length = 0;
    while(j<n)
    {
        while(i<=j && sum > k)
        {
            sum-=a[i];
            i++;
        }
        if(sum == k)
        {
            length = max(length,j-i+1);
        }
        j++;
        sum += a[j];
    }
    return length;
}