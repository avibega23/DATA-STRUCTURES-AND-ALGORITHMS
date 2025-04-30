class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int cnt = 0;
            for(int i = 0;i<nums.size();i++)
            {
                int newCnt = (int)log10(nums[i])+1;
                cnt += (newCnt %2==0)?1:0;
            }
            return cnt;
        }
    };