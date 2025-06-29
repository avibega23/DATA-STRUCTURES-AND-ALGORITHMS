//memoization
int recurse(vector<vector<int>>&nums,int ind,int par,vector<vector<int>>&dp)
{
    if(ind == 0)
    {
        int maxi = 0;
        for(int i = 0;i<nums[ind].size();i++)
        {
            if(i != par)
            maxi = max(nums[ind][i],maxi);
        }
        return dp[ind][par] = maxi;
    }
    if(dp[ind][par]!=-1) return dp[ind][par];
    int sum = 0;
    for(int i = 0;i<nums[ind].size();i++)
    {
        if(i!=par)
        sum = max(sum,nums[ind][i]+recurse(nums,ind-1,i,dp));
    }
    return dp[ind][par] = sum;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return recurse(points,n-1,3,dp);
}


//tabulation