class Solution {
    public:
        int characterReplacement(string s, int k) {
            int maxLen = 0;
            int maxFreq = 0;
            unordered_map<int,int>mpp;
            int i = 0;
            int j = 0;
            while(j<s.size())
            {
    
                mpp[s[j]-'A']++;
                maxFreq = max(maxFreq,mpp[s[j]-'A']);
                while(j-i+1-maxFreq>k)
                {
                    mpp[s[i]-'A']--;
                    maxFreq = 0;
                    for(auto it:mpp)
                    {
                        maxFreq = max(maxFreq,it.second);
                    }
                    i++;
                }
                maxLen = max(maxLen,j-i+1);
                j++;
            }
            return maxLen;
        }
    };