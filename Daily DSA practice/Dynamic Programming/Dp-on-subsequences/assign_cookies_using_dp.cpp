class Solution {
public:
    int recurse(int i,int j,vector<int>&g,vector<int>&s,vector<vector<int>>&dp)
    {
        if(i<0 || j < 0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0;
        if(g[i]<=s[j])
            take = 1+recurse(i-1,j-1,g,s,dp);

        int skipChild = recurse(i-1,j,g,s,dp);
        int skipCookie = recurse(i,j-1,g,s,dp);


        return  dp[i][j] = max(take,skipCookie);
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        vector<vector<int>>dp(g.size(),vector<int>(s.size(),-1));
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        return recurse(g.size()-1,s.size()-1,g,s,dp);
    }
};