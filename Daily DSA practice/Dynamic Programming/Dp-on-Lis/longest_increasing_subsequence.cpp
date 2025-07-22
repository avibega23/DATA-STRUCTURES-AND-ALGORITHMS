class Solution {
public:
    int recurse(vector<int>&nums,int ind,int parent,vector<vector<int>>&dp)
    {
        int n = nums.size();
        if(ind == n) return 0;
        if(dp[ind][parent+1]!=-1) return dp[ind][parent+1];

        int nonTake = recurse(nums,ind+1,parent,dp);
        int take = 0;
        if(parent == -1||nums[ind]>nums[parent])
            take = 1 + recurse(nums,ind+1,ind,dp);

        return dp[ind][parent+1] = max({take,nonTake});
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return recurse(nums,0,-1,dp);
    }
};
