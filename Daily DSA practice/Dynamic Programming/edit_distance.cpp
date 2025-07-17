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
//
