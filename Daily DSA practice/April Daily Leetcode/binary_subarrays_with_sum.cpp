class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int len = 0;
        unordered_map<int,int>mpp;
        int prefixSum = 0;
        mpp[prefixSum]++;
        for(int i = 0;i<nums.size();i++)
        {
            prefixSum += nums[i];
            if(mpp.find(prefixSum-goal)!=mpp.end())
            {
                len+= mpp[prefixSum-goal];
            }
            mpp[prefixSum]++;
        }

        return len;
    }
};