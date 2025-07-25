// reursion + memoization
class Solution {
public:
    int recurse(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = (recurse(i-1,j,s,t,dp) + recurse(i-1,j-1,s,t,dp));
        return dp[i][j] = recurse(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recurse(n-1,m-1,s,t,dp);
    }
};

//tabulation Solution
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j = 0;j<=n;j++)
        {
            dp[j][0] = 1;
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = (int)((long long)dp[i-1][j] + dp[i-1][j-1]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};


