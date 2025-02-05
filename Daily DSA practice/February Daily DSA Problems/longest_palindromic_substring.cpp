class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int maxLen = 0;
        for(int i = 0;i<s.size();i++)
        {
            int l = i;int r = i;
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(r-l+1>maxLen)
                {
                    maxLen = r-l+1;
                    ans = s.substr(l,maxLen);
                }
                l--;
                r++;                
            }
            l = i;r = i+1;
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(r-l+1>maxLen)
                {
                    maxLen = r-l+1;
                    ans = s.substr(l,maxLen);
                }
                l--;
                r++;                
            }
        }
        return ans;
    }
};