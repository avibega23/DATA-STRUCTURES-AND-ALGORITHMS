//https://leetcode.com/problems/palindrome-partitioning-ii/description/

class Solution {
public:
    bool is_palindrone(string s)
    {
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int recurse(string &s,int i,vector<int>&dp)
    {
        int n = s.size();
        if(i == n) return 0;

        if(dp[i]!=-1) return dp[i];

        int mini = INT_MAX;
        string temp = "";

        for(int k = i;k<n;k++)
        {
            temp += s[k];
            if (is_palindrone(temp)) {
                mini = min(mini, 1 + recurse(s, k + 1, dp));
            }
        }
        return dp[i] =  mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return recurse(s,0,dp)-1;
    }
};
