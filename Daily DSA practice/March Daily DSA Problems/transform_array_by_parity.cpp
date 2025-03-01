class Solution {
    public:
        vector<int> transformArray(vector<int>& nums) {
            for(int i = 0;i<nums.size();i++)
                {
                    if(nums[i]%2==0)
                    {
                        nums[i] = 0;
                    }
                    else if(nums[i]%2==1)
                    {
                        nums[i]= 1;
                    }
                }
            // int i = 0;
            // int j = 0;
            // while(j<nums.size())
            //     {
            //         while(i<nums.size()&&nums[i]!=1)
            //             {
            //                 i++;
            //             }
            //         if(nums[j]==0 && i<nums.size())
            //         {
            //             swap(nums[i],nums[j]);
            //         }
            //         j++;
            //     }
            // return nums;
            sort(nums.begin(),nums.end());
            return nums;
        }
    };©leetcode