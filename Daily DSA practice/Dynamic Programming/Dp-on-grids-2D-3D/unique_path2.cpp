class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        vector<int>prev(n,0);
        
        for(int i = 0; i < m; i++)
        {
            vector<int>temp(n,0);

            for(int j = 0; j < n; j++)
            {
                if(nums[i][j]==1) continue;
                if(i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;
                
                if(i > 0) up = prev[j];

                if(j > 0) left = temp[j-1];

                temp[j] = up + left;               
            }

            prev = temp;
        }

        return prev[n-1];
    }
};