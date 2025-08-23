class Solution {
public:
    void dfs(vector<vector<char>>&board,vector<vector<int>>&vis,int dRow[],int dCol[],int r , int c)
    {
        int n = board.size();
        int m = board[0].size();
        vis[r][c] = 1;
        for(int i = 0;i<4;i++)
        {
            int nr = r + dRow[i];
            int nc = c + dCol[i];
            if(nr >= 0 && nr < n && nc >=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O')
            {
                dfs(board,vis,dRow,dCol,nr,nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(),m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,-1,0,1};
        for(int j = 0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j] == 'O')
            {
                dfs(board,vis,dRow,dCol,0,j);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O')
            {
                dfs(board,vis,dRow,dCol,n-1,j);
            }
        }
        for(int i = 0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0] == 'O')
            {
                dfs(board,vis,dRow,dCol,i,0);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O')
            {
                dfs(board,vis,dRow,dCol,i,m-1);
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};