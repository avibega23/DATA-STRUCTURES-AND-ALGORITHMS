class Solution {
public:
    int recurse(vector<int>&nums,int ind,int target,int s,vector<vector<int>>&dp,int totSum)
    {
        if(ind == 0)
        {
            int sum = 0;
            if(s + nums[ind] == target) sum++;
            if(s - nums[ind] == target) sum++;

            return sum;
        }
        if(dp[ind][s+totSum]!=-1) return dp[ind][s+totSum];

        int plus = recurse(nums,ind-1,target,s+nums[ind],dp,totSum);
        int minus = recurse(nums,ind-1,target,s-nums[ind],dp,totSum);

        return dp[ind][s+totSum] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto it:nums)
        {
            sum += it;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(sum+sum+1,-1)); 
        return recurse(nums,nums.size()-1,target,0,dp,sum);
    }
};