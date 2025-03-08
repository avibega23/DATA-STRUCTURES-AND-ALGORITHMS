class Solution
{
public:
    void helper(vector<vector<int>> &data, vector<int> &nums, vector<int> &ans, int target, int i)
    {
        if (target == 0)
        {
            data.push_back(ans);
            return;
        }
        if (i >= nums.size())
        {
            return;
        }
        if (nums[i] <= target)
        {
            ans.push_back(nums[i]);
            helper(data, nums, ans, target - nums[i], i);
            ans.pop_back();
        }

        helper(data, nums, ans, target, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> data;
        vector<int> ans;
        helper(data, candidates, ans, target, 0);
        return data;
    }
};
>>>>>>> be15416cc66d85f11523d196071ea5e0e670eb3c
