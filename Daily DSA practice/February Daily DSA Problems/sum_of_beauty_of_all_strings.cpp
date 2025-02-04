class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for(int i = 0;i<s.size();i++)
        {   
            vector<int>hash(26,0);
            for(int j = i;j<s.size();j++)
            {
                hash[s[j]-'a']++;
                int cnt1 = 0;int cnt2 = INT_MAX;
                for(int k = 0;k<hash.size();k++)
                {
                    if(hash[k]>cnt1)
                    {
                        cnt1 = hash[k];
                    }
                    if(hash[k]<cnt2 && hash[k]!=0)
                    {
                        cnt2 = hash[k];
                    }
                }
                sum += cnt1-cnt2;
            }
        }
        return sum;
    }
};


        