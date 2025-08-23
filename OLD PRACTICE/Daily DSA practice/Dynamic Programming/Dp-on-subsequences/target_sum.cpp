//Recursive solution with memoization
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

//Tabulation
//we are using the problem subset sum equals target into that
class Solution {
public:
    int subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
        vector<vector<int>>dp(n,vector<int>(k+1,0));

        for(int i = 0;i<n;i++)
        {
            dp[i][0] = 1;
        }
        if (arr[0] >= 0 && arr[0] <= k)
            dp[0][arr[0]] += 1;
        for(int index = 1;index<n;index++)
        {
            for(int target = 0;target <= k;target++)
            {
                int nonPick = dp[index-1][target];
                int pick = 0;
                if(target>=arr[index])
                pick = dp[index-1][target-arr[index]];

                dp[index][target] = pick+nonPick;
            }
        }
        return dp[n-1][k];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(auto it:nums) total += it;

        if((target + total)%2 != 0) return 0;
        if(target+total < 0) return 0;
        int s1 = (target+total)/2;

        return subsetSumToK(nums.size(),s1,nums);
    }
};