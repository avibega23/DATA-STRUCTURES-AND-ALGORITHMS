class Solution {
    public:
        int formula(vector<int>&nums,int k)
        {
            unordered_map<int,int>mpp;
            int i = 0;
            int j = 0;
            int cnt = 0;
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
                cnt += (j-i+1);
                j++;
            }
            return cnt;
        }
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int,int>mpp;
            for(int i = 0;i<nums.size();i++)
            {
                mpp[nums[i]]++;
            }
            int k = mpp.size();
            return formula(nums,k)-formula(nums,k-1);
        }
    };