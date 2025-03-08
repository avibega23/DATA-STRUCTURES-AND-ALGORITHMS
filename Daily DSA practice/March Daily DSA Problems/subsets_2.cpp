class Solution {
    public:
        void helper(vector<int>&nums,vector<vector<int>>&data,vector<int>ans,int index)
        {
            data.push_back(ans);
            int checker = INT_MIN;
            for(int i = index;i<nums.size();i++)
            {
                if(checker == nums[i]) continue;
                else 
                {
                    checker = nums[i];
                    ans.push_back(nums[i]);
                    helper(nums,data,ans,i+1);
                    ans.pop_back();
                }
            }
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>>data;
            vector<int>ans;
            helper(nums,data,ans,0);
            
            return data;
        }
    };