class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
            unordered_map<int,int>mpp;
            int prefixSum = 0;
            mpp[prefixSum]++;
            int cnt = 0;
            for(int i = 0;i<nums.size();i++)
            {
                prefixSum += nums[i];
                int mod = (prefixSum % k +k)%k;
    
                if(mpp.find(mod)==mpp.end())
                {
                    mpp[mod]++;
                }
                else
                {
                    cnt += mpp[mod];
                    mpp[mod]++;
                }
            }
            return cnt;
        }
    };