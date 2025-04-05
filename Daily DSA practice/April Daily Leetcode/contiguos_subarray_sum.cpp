class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            unordered_map<int,int>mpp;
            mpp[0] = -1;
            int total = 0;
            for(int i = 0;i<nums.size();i++)
            {
                total+=nums[i];
                int remainder = total % k;
                if(mpp.find(remainder)==mpp.end())
                {
                    mpp[remainder] = i;
                }
                else if(i-mpp[remainder]>1)
                {
                    return true;
                }
            }
            return false;
            
        }
    };