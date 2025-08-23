class Solution {
    public:
        void helper(vector<int>&nums,vector<int>ans,vector<vector<int>>&data,int i)
        {
            if(i>=nums.size())
            {
                data.push_back(ans);
                return;
            }
            helper(nums,ans,data,i+1);
            
            ans.push_back(nums[i]);
            helper(nums,ans,data,i+1);
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>>data;
            vector<int>ans;
            helper(nums,ans,data,0);
            return data;
        }
    };