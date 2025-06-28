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


//tabulated form 

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[0] = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            int take = nums[i];if(i>1)take += dp[i-2];
            int nonTake = dp[i-1];
            dp[i] = max(take,nonTake);
        }
        return dp[nums.size()-1];
    }
};