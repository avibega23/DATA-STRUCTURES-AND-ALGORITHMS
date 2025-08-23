//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

//recursion + memoization 1(Memory Limit Exceeded Error)
class Solution {
public:
    int recurse(vector<int>&cuts,int i,int j,vector<vector<int>>&dp)
    {
        if(i == j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = INT_MAX;
        for(int k = 0;k<cuts.size();k++)
        {
            int cost = INT_MAX;
            if(cuts[k] > i && cuts[k] < j)
                cost = (j-i) + recurse(cuts,i,cuts[k],dp) + recurse(cuts,cuts[k],j,dp);
            if(cost < mini) mini = cost;
        }
        return dp[i][j] = mini == INT_MAX ? 0 : mini;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recurse(cuts,0,n,dp);
    }
};

// Recursion + memoization 2

