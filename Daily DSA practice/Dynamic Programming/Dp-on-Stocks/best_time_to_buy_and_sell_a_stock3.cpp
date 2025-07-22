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

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));
        int n = prices.size();
        for(int i = 0;i<prices.size();i++)
        {
            for(int j = 0;j<2;j++)
            {
                dp[i][j][0] = 0;
            }
        }
        dp[n][0][0] = dp[n][0][1] = dp[n][0][2] = dp[n][1][0] = dp[n][1][1] = dp[n][1][2] = 0;
        for(int i = n-1;i>=0;i--)
        {
            for(int j = 0;j<2;j++)
            {
                for(int k = 1;k<3;k++)
                {
                    if(j == 1)
                    dp[i][j][k] = max(dp[i+1][j][k],prices[i] + dp[i+1][0][k-1]);
                    else
                    dp[i][j][k] = max(dp[i+1][j][k],-prices[i] + dp[i+1][1][k]);
                }
            }
        }

        return dp[0][0][2];
    }
};


