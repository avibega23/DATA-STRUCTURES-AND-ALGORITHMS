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
//
