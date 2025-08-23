class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            unordered_map<int,vector<int>>mpp;
            int n = grid.size();
            int m = grid[0].size();
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<m;j++)
                {
                    mpp[i-j].push_back(grid[i][j]);
                }
            }
            for(auto it:mpp)
            {
                if(it.first>=0) sort(mpp[it.first].begin(),mpp[it.first].end(),greater<int>());
                else sort(mpp[it.first].begin(),mpp[it.first].end());
            }
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<m;j++)
                {
                    grid[i][j] = mpp[i-j].front();
                    mpp[i-j].erase(mpp[i-j].begin());
                }
            }
            return grid;
        }
    };