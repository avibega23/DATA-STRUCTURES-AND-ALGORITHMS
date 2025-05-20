class Solution {
public:
    bool isHeap(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
        {
            int left = 2*i+1;
            int right = 2*i+2;
            if(left < nums.size() && nums[left]<nums[i]) return false;
            if(right < nums.size() && nums[right]<nums[i]) return false;
        }
        return true;
    }
};