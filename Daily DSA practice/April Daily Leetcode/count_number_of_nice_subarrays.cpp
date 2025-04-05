class Solution {
    public:
        int fun(vector<int>&nums,int goal)
        {
            if(goal<0) return 0;
            int l = 0,r = 0;
            int sum = 0;
            int cnt = 0;
            while(r<nums.size())
            {
                sum += nums[r];
                while(sum > goal)
                {
                    sum -= nums[l];
                    l++;
                }
                cnt += r-l+1;
                r++;
            }
            return cnt;
        }
        int numberOfSubarrays(vector<int>& nums, int k) {
            for(int i = 0;i<nums.size();i++)
            {
                nums[i] = (nums[i]%2==0)?0:1;
            }
            return fun(nums,k)-fun(nums,k-1);
        }
    };