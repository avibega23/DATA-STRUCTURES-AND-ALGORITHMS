//recursive solution  
class Solution {
public:
    int recurse(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(j<0) return i+1;
        if(i < 0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        int match = INT_MAX;
        if(s[i]==t[j])
        {
            match = recurse(i-1,j-1,s,t,dp);
        }

        int insert = 1 + recurse(i,j-1,s,t,dp);
        int del = 1 + recurse(i-1,j,s,t,dp);
        int rep = 1 + recurse(i-1,j-1,s,t,dp);

        return dp[i][j] = min({match,insert,del,rep});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return recurse(n-1,m-1,word1,word2,dp);
    }
};

//tabulation solution 

class Solution {
public:
    // int recurse(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    // {
    //     if(j<0) return i+1;
    //     if(i < 0) return j+1;
    //     if(dp[i][j]!=-1) return dp[i][j];
        
    //     if(s[i]==t[j])
    //     {
    //         match = recurse(i-1,j-1,s,t,dp);
    //     }

    //     int insert = 1 + recurse(i,j-1,s,t,dp);
    //     int del = 1 + recurse(i-1,j,s,t,dp);
    //     int rep = 1 + recurse(i-1,j-1,s,t,dp);

    //     return dp[i][j] = min({match,insert,del,rep});
    // }
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++)
        {
            dp[i][0] = i;
        }
        for(int i = 1;i<=m;i++)
        {
            dp[0][i] = i;
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                int match = 1e9 + 7;
                if(s[i-1]==t[j-1])
                {
                    match = dp[i-1][j-1];
                    // recurse(i-1,j-1,s,t,dp);
                }

                int insert = 1 + dp[i][j-1];
                // recurse(i,j-1,s,t,dp);
                int del = 1 + dp[i-1][j];
                // recurse(i-1,j,s,t,dp);
                int rep = 1 + dp[i-1][j-1];
                // recurse(i-1,j-1,s,t,dp);

                dp[i][j] = min({match,insert,del,rep});
            }
        }
        return dp[n][m];
        // recurse(n-1,m-1,word1,word2,dp);
    }
};


