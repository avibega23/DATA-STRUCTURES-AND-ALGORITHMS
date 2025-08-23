class Solution {
    public:
        void helper(int value,vector<int>&ans,int target,int size,vector<vector<int>>&data,int index)
        {
            if(index == size)
            {
                if(target==0)
                {
                    data.push_back(ans);
                }
                return;
            }
            
            if(value>target||value>9) return;
        
            ans.push_back(value);
            helper(value+1,ans,target-value,size,data,index+1);
            ans.pop_back();
            helper(value+1,ans,target,size,data,index);
            
        }
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>>data;
            vector<int>ans;
            helper(1,ans,n,k,data,0);
            return data;
        }
    };