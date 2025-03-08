<<<<<<< HEAD

class Solution {
    public:
        void helper(vector<int>&nums,int target,vector<int>&ans,int index,vector<vector<int>>&data)
        {
            if(target==0)
            {
                data.push_back(ans);
                return;
            }
            if(index>=nums.size())
            {
                return;
            }
            int checker = INT_MIN;
            for(int i = index;i<nums.size();i++)
            {
                if(nums[i]==checker) continue;
                else
                {
                    checker = nums[i];
                    if(nums[i]>target)break;
                    ans.push_back(nums[i]);
                    helper(nums,target-nums[i],ans,i+1,data);
                    ans.pop_back();
                }
                
            }
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<vector<int>>data;
            vector<int>ans;
            helper(candidates,target,ans,0,data);
            return data;
        }
    };
=======
