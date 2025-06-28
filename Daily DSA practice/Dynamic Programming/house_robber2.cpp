class Solution {
public:
    int recurse(const vector<int>&nums, int ind, vector<int>& dp) {
        if (ind == 0) return nums[0];
        if (ind <a 0) return 0;
        if (dp[ind] != -1) return dp[ind];

        int take = nums[ind] + recurse(nums, ind - 2, dp);
        int nonTake = recurse(nums, ind - 1, dp);

        return dp[ind] = max(take, nonTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);
        int case1 = recurse(vector<int>(nums.begin(), nums.end() - 1), n - 2, dp1);
        int case2 = recurse(vector<int>(nums.begin() + 1, nums.end()), n - 2, dp2);

        return max(case1, case2);
    }
};
