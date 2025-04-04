class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int i = 0;
            int j = 0;
            int maxLen = 0;
            unordered_map<char,int>mpp;
            while(j<s.size())
            {
                if(mpp.find(s[j])!=mpp.end())
                {
                    i = max(i,mpp[s[j]]+1);
                    maxLen = max(maxLen,j-i);
                }
                mpp[s[j]] = j;
                j++;
                maxLen = max(maxLen,j-i);
            }
            return maxLen;
        }
    };