class Solution {
    public:
    void helper(vector<int>&nums,vector<int>ans,vector<vector<int>>&data,int i)
        {
            if(i>=nums.size())
            {
                data.push_back(ans);
                return;
            }
            helper(nums,ans,data,i+1);//calling the function wthout including the current element
            
            ans.push_back(nums[i]);
            helper(nums,ans,data,i+1);//calling the function by including the current element
        }
        int subsetXORSum(vector<int>& nums) {
            vector<vector<int>>data;
            vector<int>ans;
            helper(nums,ans,data,0);
            int sum = 0;
            for(int i = 0;i<data.size();i++)
            {
                int num = 0;
                for(int j = 0;j<data[i].size();j++)
                {
                    num = num^data[i][j];
                }
                sum+=num;
            }
            return sum;
        }
    };