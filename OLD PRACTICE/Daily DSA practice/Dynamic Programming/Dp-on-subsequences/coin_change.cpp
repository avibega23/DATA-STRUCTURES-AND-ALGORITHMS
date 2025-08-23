class Solution {
public:
    int recurse(vector<int>&coins,int ind,int amount,vector<vector<int>>&dp)
    {
        if(amount == 0) return 0;
        if(ind  < 0) return 1e9;

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take =  1e9 ;
        if(amount >= coins[ind])
        take = 1 + recurse(coins,ind,amount-coins[ind],dp);
        int nonTake = recurse(coins,ind-1,amount,dp);
        return dp[ind][amount] = min({take,nonTake});
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans = recurse(coins,coins.size()-1,amount,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};