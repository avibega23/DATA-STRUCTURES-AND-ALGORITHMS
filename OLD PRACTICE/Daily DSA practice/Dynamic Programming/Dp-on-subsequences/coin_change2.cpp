//recursion + memoization
class Solution {
public:
    int recurse(int amount,vector<int>&coins,int index,vector<vector<int>>&dp)
    {
        if(amount == 0) return 1;
        if(index == 0) return (amount%coins[index]==0);

        if(dp[index][amount]!=-1) return dp[index][amount];
        int take = 0;
        if(coins[index]<=amount)
            take = recurse(amount-coins[index],coins,index,dp);
        int nonTake = recurse(amount,coins,index-1,dp);

        return dp[index][amount] = take+nonTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return recurse(amount,coins,coins.size()-1,dp);
    }
};

//tabulation + space optimization   