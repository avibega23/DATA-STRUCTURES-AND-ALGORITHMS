class Solution {
    public:
        string clearDigits(string s) {
            string ans = "";
            vector<int>hash(s.size(),0);
            for(int i = 0;i<s.size();i++)
            {
                if(s[i]-'0'>= 0 && s[i]-'0'<=9)
                {
                    hash[i] = 1;
                    for(int j = i-1;j>=0;j--)
                    {
                        if(hash[j]==0)
                        {
                            hash[j] = 1;
                            break;
                        }
                    }
                }
            }
            for(int i = 0;i<s.size();i++)
            {
                if(hash[i]==0)
                {
                    ans += s[i];
                }
            }
            return ans;
        }
    };