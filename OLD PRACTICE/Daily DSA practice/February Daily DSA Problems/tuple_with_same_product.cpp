class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i = 0;i<nums.size()-1;i++)
        {
            for(int j =i+1;j<nums.size();j++)
            {
                mpp[nums[i]*nums[j]]++;
            }
        }
        int cnt= 0;
        for(auto it:mpp)
        {
            if(it.second>1)
            {
                cnt += (8*((it.second*(it.second-1))/2));
            }
        }
        return cnt;
    }
};