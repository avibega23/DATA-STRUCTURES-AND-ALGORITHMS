// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int i,int j,int baseR,int baseC,vector<int>&nRow,vector<int>&nCol,vector<pair<int,int>>&shape )
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        shape.push_back({i-baseR,j-baseC});
        for(int k = 0;k<4;k++)
        {
            int r = i+nRow[k];
            int c = j+nCol[k];
            if(r>=0 && r<n && c>=0 && c < m && grid[r][c]==1 && !vis[r][c])
            {
                dfs(grid,vis,r,c,baseR,baseC,nRow,nCol,shape);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int cnt = 0;
        vector<int>nRow = {0,1,0,-1};
        vector<int>nCol = {1,0,-1,0};
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        set<vector<pair<int,int>>>st;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>shape;
                    dfs(grid,vis,i,j,i,j,nRow,nCol,shape);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};
