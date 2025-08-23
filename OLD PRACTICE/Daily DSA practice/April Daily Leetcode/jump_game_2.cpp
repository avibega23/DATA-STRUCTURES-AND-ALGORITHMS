class Solution {
    public:
        int jump(vector<int>& nums) {
            int currEnd = 0;
            int farthest = 0;
            int jump = 0;
            for(int i = 0;i<nums.size()-1;i++)
            {
                farthest = max(farthest,nums[i]+i);
                if(i == currEnd)
                {
                    jump++;
                    currEnd = farthest;
                }
            }
            return jump;
        }
    };