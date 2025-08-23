class Solution {
    public:
        void helper(string digits,vector<string>&mainAns,string ans,int index,unordered_map<char,string>&mpp)
        {
            if(index==digits.size())
            {
                mainAns.push_back(ans);
                return;
            }
            string current = mpp[digits[index]];
            for(int i = 0;i<current.size();i++)
            {
                ans.push_back(current[i]);
                helper(digits,mainAns,ans,index+1,mpp);
                ans.pop_back();
            }
        }
        vector<string> stringGenerator(string digits)
        {
            unordered_map<char,string> mpp;
            mpp['2']="abc";
            mpp['3']="def";
            mpp['4']="ghi";
            mpp['5']="jkl";
            mpp['6']="mno";
            mpp['7']="pqrs";
            mpp['8']="tuv";
            mpp['9']="wxyz";
    
            vector<string>data;
            if(digits.size()==0)return data;
            helper(digits,data,"",0,mpp);
            return data;
        }
        vector<string> letterCombinations(string digits) {
            return stringGenerator(digits);
        }
    };