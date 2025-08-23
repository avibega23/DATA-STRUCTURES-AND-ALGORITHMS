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


    class Solution {
        public:
            int lowerBound(vector<int>&nums,int low,int high,int target)
            {
                while(low<=high)
                {
                    int mid = low+(high-low)/2;
                    if(nums[mid]>=target)
                    {
                        high = mid-1;
                    }
                    else
                    {
                        low = mid+1;
                    }
                }
                return low;
            }
            int upperBound(vector<int>&nums,int low,int high,int target)
            {
                while(low<=high)
                {
                    int mid = low+(high-low)/2;
        
                    if(nums[mid]>target)
                    {
                        high = mid-1;
                    }
                    else
                    {
                        low = mid+1;
                    }
                }
                return low;
            }
            long long countFairPairs(vector<int>& nums, int lower, int upper) {
                long long cnt = 0;
                sort(nums.begin(),nums.end());
                for(int i = 0;i<nums.size();i++)
                {
                    int left = lowerBound(nums,i+1,nums.size()-1,lower-nums[i])-1;
                    int right = upperBound(nums,i+1,nums.size()-1,upper-nums[i])-1;
                    cnt += right-left;
                }
                return cnt;
            }
        };w