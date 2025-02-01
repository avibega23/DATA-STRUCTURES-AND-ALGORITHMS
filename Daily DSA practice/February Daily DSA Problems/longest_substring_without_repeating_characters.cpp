class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int maxLen = 0;
        int l = 0;
        for(int r = 0;r<s.size();r++)
        {
            if(mpp.find(s[r])!=mpp.end()&&mpp[s[r]]>=l)
            {
                
                l = mpp[s[r]]+1;
            }
            maxLen = max(maxLen,r-l+1);
            mpp[s[r]] = r;
        }
        return maxLen;
    }
};