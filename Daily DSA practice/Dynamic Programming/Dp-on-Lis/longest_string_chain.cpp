//https://leetcode.com/problems/longest-string-chain/description/

class Solution {
public:
    bool compare(string a,string b)
    {
        int n = a.size(),m = b.size();
        if(n != m+1) return false;
        int i = 0, j = 0;
        while(i<n)
        {
            if(a[i]!=b[j]) i++;
            else
            {
                i++; j++;
            }
        }
        if(i == n && j == m) return true;
        else return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int>dp(n,1);
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(compare(words[i],words[j]) && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
