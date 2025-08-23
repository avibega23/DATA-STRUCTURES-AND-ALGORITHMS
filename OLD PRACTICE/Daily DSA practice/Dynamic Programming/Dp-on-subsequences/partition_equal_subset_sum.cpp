class Solution {
public:
    
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Write your code here.
        vector<int>dp(k+1,0);

        dp[0] = 1;
        if(arr[0]<=k)
        dp[arr[0]] = 1;
        for(int index = 1;index<n;index++)
        {
            vector<int>temp(k+1,0);
            temp[0] = 1;
            for(int target = 1;target <= k;target++)
            {
                bool nonPick = dp[target];
                bool pick = false;
                if(target>=arr[index])
                pick = dp[target-arr[index]];

                temp[target] = (pick||nonPick);
            }
            dp = temp;
        }

        return dp[k];
    }
    bool canPartition(vector<int>& nums) {
        int  sum  = 0;
        for(auto it:nums)
        {
            sum += it;
        }
        if(sum % 2 == 1) return false;
        return subsetSumToK(nums.size(),sum/2,nums);
    }
};