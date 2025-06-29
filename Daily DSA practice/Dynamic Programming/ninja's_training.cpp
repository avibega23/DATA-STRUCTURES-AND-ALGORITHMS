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
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][1],points[0][0]);
    dp[0][3] = max(points[0][1],max(points[0][0],points[0][2]));

    for(int i = 1;i<n;i++)
    {
        for(int last = 0;last<4;last++)
        {
            for(int j = 0;j<3;j++)
            {
                if(j != last)
                {
                    int point = points[i][j] + dp[i-1][j];
                    dp[i][last] = max(dp[i][last],point);
                }
            }
        }
    }

    return dp[n-1][3];
}