int n = nums.size();
        vector<vector<int>>data;
        int subset = 1<<nums.size();

        for(int i = 0;i<subset;i++)
        {
            vector<int>ans;
            for(int j = 0;j<n;j++)
            {
                if(i & (1<<j))
                {
                    ans.push_back(nums[j]);
                }
            }
            data.push_back(ans);
        }
        return data;