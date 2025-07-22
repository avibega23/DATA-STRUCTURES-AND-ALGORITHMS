//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int x, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(x+1, 0)));
        int n = prices.size();
        for(int i = n-1;i>=0;i--)
        {
            for(int j = 0;j<2;j++)
            {
                for(int k = 1;k<=x;k++)
                {
                    if(j == 1)
                    dp[i][j][k] = max(dp[i+1][j][k],prices[i] + dp[i+1][0][k-1]);
                    else
                    dp[i][j][k] = max(dp[i+1][j][k],-prices[i] + dp[i+1][1][k]);
                }
            }
        }

        return dp[0][0][x];
    }
};
