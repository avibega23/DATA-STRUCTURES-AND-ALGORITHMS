class Solution {
public:
    int recurse(vector<int>&prices,int ind,int buy,vector<vector<int>>&dp)
    {
        int n = prices.size();
        if(ind == n) return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];

        long profit = 0;

        if(buy == 0) profit = max(0+recurse(prices,ind+1,0,dp),-prices[ind]+recurse(prices,ind+1,1,dp));
        else profit = max(0+recurse(prices,ind+1,1,dp),prices[ind]+recurse(prices,ind+1,0,dp));

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return recurse(prices,0,0,dp);
    }
};
