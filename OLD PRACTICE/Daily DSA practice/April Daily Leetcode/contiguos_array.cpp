class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            int maxLen = 0;
            int prefixSum = 0;
            unordered_map<int,int>mpp;
            mpp[0] = -1;
            for(int i = 0;i<nums.size();i++)
            {
                if(nums[i]==1)
                {
                    prefixSum += 1;
                }
                else
                {
                    prefixSum -=1;
                }
                if(mpp.find(prefixSum)!=mpp.end())
                {
                    maxLen = max(maxLen,i-mpp[prefixSum]);
                }
                else
                    mpp[prefixSum] = i;
                
            }
            return maxLen;
        }
    };