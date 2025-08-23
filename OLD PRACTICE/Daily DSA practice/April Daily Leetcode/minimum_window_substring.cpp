class Solution {
    public:
        string minWindow(string s, string t) {
            vector<int>sMap(128,0),tMap(128,0);
            int i = 0,j = 0;
            for(char it:t)
            {
                tMap[it]++;
            }
            int have = 0,need = 0,start = 0,minLen = INT_MAX;
            for(int i = 0;i<128;i++)
            {
                if(tMap[i]>0)
                {
                    need++;
                }
            }
            while(j<s.size())
            {
                sMap[s[j]]++;
                if(tMap[s[j]]>0 && sMap[s[j]]==tMap[s[j]])
                {
                    have++;
                }
                while(have == need)
                {
                    if((j-i+1)<minLen)
                    {
                        start = i;
                        minLen = j-i+1;
                    }
                    sMap[s[i]]--;
                    if(tMap[s[i]]>0 && sMap[s[i]]<tMap[s[i]])
                    {
                        have--;   
                    }
                    i++;
                }
                j++;
            }
            return minLen == INT_MAX ? "" : s.substr(start,minLen);
        }
    };