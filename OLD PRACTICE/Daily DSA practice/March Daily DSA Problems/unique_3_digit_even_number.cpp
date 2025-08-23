class Solution {
    public:
        
        void helper(vector<int>&digits,vector<bool>&ans,int count,int num,unordered_set<int>&st)
        {
            if(count == 3)
            {
                if(num%2==0)
                {
                    st.insert(num);
                }
                return;
            }
    
            for(int i = 0;i<digits.size();i++)
                {
                    if(digits[i]==0 && count == 0) continue;
                    if(!ans[i])
                    {
                        ans[i] = true;
                        helper(digits,ans,count+1,num*10+digits[i],st);
                        ans[i] = false;
                    }
                }
        }
        int totalNumbers(vector<int>& digits) {
            vector<bool>ans(digits.size(),false);
            unordered_set<int>st;
            helper(digits,ans,0,0,st);
            return st.size();
        }
    
    };