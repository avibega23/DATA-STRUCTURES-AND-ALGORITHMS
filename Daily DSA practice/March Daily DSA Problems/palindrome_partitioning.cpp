class Solution {
    public:
        bool isPalindrone(string s,int start,int end)
        {
            while(start<=end)
            {
                if(s[start++]!=s[end--])
                {
                    return false;
                }
            }
            return true;
        }
        void helper(string s,vector<string>&ans,vector<vector<string>>&data,int index)
        {
            if(index == s.size())
            {
                data.push_back(ans);
                return;
            }
            for(int i = index;i<s.size();i++)
            {
                if(isPalindrone(s,index,i))
                {
                    ans.push_back(s.substr(index,i-index+1));
                    helper(s,ans,data,i+1);
                    ans.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<vector<string>>data;
            vector<string>ans;
            helper(s,ans,data,0);
            return data;
        }
    };