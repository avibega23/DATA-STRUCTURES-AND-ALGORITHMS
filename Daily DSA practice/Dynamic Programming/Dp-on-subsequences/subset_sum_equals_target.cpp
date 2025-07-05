//recursive solution
#include <bits/stdc++.h> 
bool recurse(int index,vector<int>&arr,int k)
{
    if(k == 0) return true;
    if(index == 0) return(arr[0]==k);

    bool nonPick = recurse(index-1,arr,k);
    bool pick = false;
    if(k>=arr[index])
    pick = recurse(index-1,arr,k-arr[index]);

    return nonPick || pick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return recurse(n-1,arr,k);
}


//memoization solution
#include <bits/stdc++.h> 
bool recurse(int index,vector<int>&arr,int k,vector<vector<int>>&dp)
{
    if(k == 0) return true;
    if(index == 0) return(arr[0]==k);
    if(dp[index][k]!=-1) return dp[index][k];
    bool nonPick = recurse(index-1,arr,k,dp);
    bool pick = false;
    if(k>=arr[index])
    pick = recurse(index-1,arr,k-arr[index],dp);

    return dp[index][k] = (pick||nonPick);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return recurse(n-1,arr,k,dp);
}


//tabulated solution

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,0));

    for(int i = 0;i<n;i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] >= 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;
    for(int index = 1;index<n;index++)
    {
        for(int target = 1;target <= k;target++)
        {
            bool nonPick = dp[index-1][target];
            bool pick = false;
            if(target>=arr[index])
            pick = dp[index-1][target-arr[index]];

            dp[index][target] = (pick||nonPick);
        }
    }

}