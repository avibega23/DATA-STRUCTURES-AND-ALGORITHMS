class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
            vector<vector<int>>dp(n+1,vector<int>(2,-1));
            dp[n][0] = 0;
            dp[n][1] = 0;
            for(int i = n-1;i>=0;i--)
            {
                for(int j = 0;j<2;j++)
                {
                    if(j == 1)
                    dp[i][j] = max(dp[i+1][1],-prices[i]+dp[i+1][0]);
                    else
                    dp[i][j] = max(dp[i+1][0],prices[i]+dp[i+1][1]-fee);
                }
            }
            return dp[0][1];
    }
};
