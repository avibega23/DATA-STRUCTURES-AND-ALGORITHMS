class Solution {
  public:
    int recurse(vector<int>&arr,int index,int n,vector<int>&dp)
    {
        if(index == n-1) return 0;
        if(dp[index]!= -1) return dp[index];
        int oneStep = abs(arr[index]-arr[index+1]) + recurse(arr,index+1,n,dp);
        int twoStep = INT_MAX;
        if(index+2 < n)
        {
            twoStep = abs(arr[index]-arr[index+2]) + recurse(arr,index+2,n,dp);
        }
        return dp[index] = min(oneStep,twoStep);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n,-1);
        return recurse(height,0,n,dp);
    }
};