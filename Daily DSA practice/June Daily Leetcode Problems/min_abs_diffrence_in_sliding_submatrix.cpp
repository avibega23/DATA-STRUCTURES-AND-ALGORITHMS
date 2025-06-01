class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1));
        for(int i = 0;i<n-k+1;i++)
        {
            for(int j = 0;j<m-k+1;j++)
            {
                vector<int>data;
                for(int l = i;l<k+i;l++)
                {
                    for(int p = j;p<k+j;p++)
                    {
                        data.push_back(grid[l][p]);
                    }
                }
                int mini = INT_MAX;
                sort(data.begin(),data.end());
                for(int x = 1;x<data.size();x++)
                {
                    if(data[x]!=data[x-1])
                    mini = min(mini,abs(data[x]-data[x-1]));
                }
                ans[i][j] = (mini==INT_MAX)?0:mini;
            }
        }
        return ans;
    }
};