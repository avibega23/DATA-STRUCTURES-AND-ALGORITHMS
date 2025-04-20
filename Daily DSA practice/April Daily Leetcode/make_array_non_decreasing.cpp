class Solution {
    public:
        int maximumPossibleSize(vector<int>& nums) {
            int maxi = INT_MIN;
            int cnt = 0;
            
            int index = -1;
            for(int i = 0;i<nums.size();i++)
                {
                    if(nums[i]>=maxi)
                    {
                        maxi = nums[i];
                        index = i;
                    }
                    else
                    {
                        cnt += i-index;
                        index = i;
                    }
                }
            return nums.size()-cnt;
        }
    };©leetcode