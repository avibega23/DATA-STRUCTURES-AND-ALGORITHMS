class Solution {
public:
    int recurse(vector<int>&nums,int ind,vector<int>&dp)
    {
        if(ind < 0) return 0;
        if(ind == 0) return nums[ind];
        if(dp[ind]!=-1) return dp[ind];

        int pick = nums[ind] + recurse(nums,ind-2,dp);

        int nonPick = recurse(nums,ind-1,dp);
        return dp[ind] = max(pick,nonPick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return recurse(nums,nums.size()-1,dp);
    }
};