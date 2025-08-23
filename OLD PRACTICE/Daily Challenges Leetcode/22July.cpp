//https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int maxi = 0;
        int sum = 0;

        int i = 0,j= 0;
        while(j<nums.size())
        {
            if(mpp.find(nums[j])==mpp.end())
            {
                sum += nums[j];
                mpp[nums[j]]++;
                j++;
                maxi = max(sum,maxi);
            }
            else
            {
                while(mpp[nums[j]]>0)
                {
                    sum -= nums[i];
                    mpp[nums[i]]--;
                    i++;
                }
                mpp.erase(nums[j]);
            }
        }
        return maxi;
    }
};
