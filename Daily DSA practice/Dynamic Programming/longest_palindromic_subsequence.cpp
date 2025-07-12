//recursive solution
class Solution {
public: 
    void recurse(int &maxi,int ind,string &s,string ans)
    {
        string temp = ans;
        reverse(temp.begin(),temp.end());
        int n = ans.size();
        if(temp==ans) maxi = max(maxi,n);
        if(ind==s.size()) return;

        recurse(maxi,ind+1,s,ans+s[ind]);
        recurse(maxi,ind+1,s,ans);
    }
    int longestPalindromeSubseq(string s) {
        int maxi = 0;
        recurse(maxi,0,s,"");
        return maxi;
    }
};

// using longest longestPalindromeSubsequence 

class Solution {
public: 
    
    int longestPalindromeSubseq(string s) {
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
        return dp[n][m];
    }
};
