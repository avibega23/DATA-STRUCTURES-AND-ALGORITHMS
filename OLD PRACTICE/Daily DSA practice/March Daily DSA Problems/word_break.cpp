class Solution {
    public:
        bool isFound(string ans,vector<string>&dict)
        {
            for(auto it:dict)
            {
                if(ans == it)
                {
                    return true;
                }
            }
            return false;
        }
        bool solve(string s,vector<string>&dict,int ind)
        {
            if(ind>=s.size()) return true;
    
            
            for(int i = ind;i<s.size();i++)
            {
                string ans = s.substr(ind,i-ind+1);
                if(isFound(ans,dict))
                {
                    if(solve(s,dict,i+1))return true;
                }
            }
            return false;
        }
        bool wordBreak(string s, vector<string>& wordDict) {
            return solve(s,wordDict,0);
        }
    };