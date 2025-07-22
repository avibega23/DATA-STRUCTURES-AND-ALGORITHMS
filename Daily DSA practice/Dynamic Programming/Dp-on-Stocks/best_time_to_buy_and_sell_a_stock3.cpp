//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//recursion + memoization
class Solution {
public:
    int recurse(vector<int>&prices,int ind,bool buy,int cnt,vector<vector<vector<int>>>&dp)
    {

        int n = prices.size();
        if(cnt == 0) return 0;
        if(ind == n) return 0;

        if(dp[ind][buy][cnt]!=-1) return dp[ind][buy][cnt];

        long profit;

        if(buy)
        {
            profit = max(recurse(prices,ind+1,buy,cnt,dp),prices[ind]+recurse(prices,ind+1,!buy,cnt-1,dp));
        }
        else
        {
            profit = max(recurse(prices,ind+1,buy,cnt,dp),-prices[ind]+recurse(prices,ind+1,!buy,cnt,dp));
        }

        return dp[ind][buy][cnt] = profit;
    }
    int maxProfit(vector<int>& prices) {
         vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return recurse(prices,0,false,2,dp);
    }
};


