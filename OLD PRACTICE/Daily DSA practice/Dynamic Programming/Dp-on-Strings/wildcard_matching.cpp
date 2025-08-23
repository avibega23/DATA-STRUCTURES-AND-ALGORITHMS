//recursion + memoization
class Solution {
public:
    bool recurse(int i,int j,string &s,string &t,char parent,vector<vector<int>>&dp)
    {

        if(i < 0 && j<0) return true;
        if(j < 0) return false;
        if (i < 0) {
            for (int k = 0; k <= j; k++)
                if (t[k] != '*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        bool match = false;
        if(s[i]==t[j])
        {
            match = recurse(i-1,j-1,s,t,parent,dp);
        }
        bool star = false;
        if(t[j]=='*')
        {
            star = recurse(i-1,j,s,t,parent,dp) || recurse(i,j-1,s,t,parent,dp);
        }
        bool question = false;
        if(t[j]=='?')  question = recurse(i-1,j-1,s,t,parent,dp);

        return dp[i][j] = match || question || star;
    }
    bool isMatch(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recurse(n-1,m-1,s,t,'\0',dp);
    }
};

//tabulation approach
class Solution {
public:
    bool isMatch(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0] = 1;
         for (int j = 1; j <= m; ++j) {
            if (t[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
               if (t[j - 1] == s[i - 1] || t[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (t[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
