class Solution {
    public:
        int fun(vector<int>&nums,int k)
        {
            int len = 0;
            int i = 0,j = 0;
            unordered_map<int,int>mpp;
            while(j<nums.size())
            {
                mpp[nums[j]]++;
                while(mpp.size()>k)
                {
                    mpp[nums[i]]--;
                    if(mpp[nums[i]]==0)
                    {
                        mpp.erase(nums[i]);
                    }
                    i++;
                }
                if(mpp.size()<=k)
                {
                    len += j-i+1;
                }
                j++;
            }
            return len;
        }
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return fun(nums,k) - fun(nums,k-1);
        }
    };