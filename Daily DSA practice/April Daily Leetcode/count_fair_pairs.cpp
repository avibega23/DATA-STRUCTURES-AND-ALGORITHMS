class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            long long cnt = 0;
            sort(nums.begin(),nums.end());
            for(int i = 0;i<nums.size();i++)
            {
                int left = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
                int right = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
                cnt += right-left;
            }
            return cnt;
        }
    };