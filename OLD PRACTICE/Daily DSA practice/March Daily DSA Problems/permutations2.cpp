class Solution {
    public:
        void solve(map<vector<int>,int>&mpp,vector<int>&nums,int index)
        {
            if(index==nums.size())
            {
                mpp[nums]++;
                return;
            }
            for(int i = index;i<nums.size();i++)
            {
                swap(nums[index],nums[i]);
                solve(mpp,nums,index+1);
                swap(nums[index],nums[i]);
            }
        }
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            map<vector<int>,int>st;
            solve(st,nums,0);
            vector<vector<int>>ans;
            for(auto it:st)
            {
                ans.push_back(it.first);
            }
            return ans;
        }
    };