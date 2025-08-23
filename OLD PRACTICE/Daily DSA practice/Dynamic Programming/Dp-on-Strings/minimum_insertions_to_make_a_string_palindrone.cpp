class Solution {
public:
    int minInsertions(string s) {
        string ans = s;
        reverse(s.begin(),s.end());
        int n = s.size();
        int m = ans.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(s[i-1]==ans[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return ans.size()-dp[n][m];
    }
};
