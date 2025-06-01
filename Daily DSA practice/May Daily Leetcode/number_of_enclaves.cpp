class Solution {
public:
    void dfs(vector<vector<int>>&board,vector<vector<int>>&vis,int dRow[],int dCol[],int r , int c)
    {
        int n = board.size();
        int m = board[0].size();
        vis[r][c] = 1;
        for(int i = 0;i<4;i++)
        {
            int nr = r + dRow[i];
            int nc = c + dCol[i];
            if(nr >= 0 && nr < n && nc >=0 && nc<m && !vis[nr][nc] && board[nr][nc]==1)
            {
                dfs(board,vis,dRow,dCol,nr,nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dRow[] = {0,1,0,-1};
        int dCol[] = {1,0,-1,0};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<m;i++)
        {
            if(grid[0][i] == 1 && !vis[0][i])
            {
                dfs(grid,vis,dRow,dCol,0,i);
            }
            if(grid[n-1][i] == 1 && !vis[n-1][i])
            {
                dfs(grid,vis,dRow,dCol,n-1,i);
            }
        }
        for(int i = 0;i<n;i++)
        {
            if(grid[i][0] == 1 && !vis[i][0])
            {
                dfs(grid,vis,dRow,dCol,i,0);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1])
            {
                dfs(grid,vis,dRow,dCol,i,m-1);
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!vis[i][j]  && grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};