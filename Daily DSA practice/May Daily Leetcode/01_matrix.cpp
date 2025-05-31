class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();int m = mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<mat.size();i++)
        {
            for(int j = 0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int nrow[4] = {1,0,-1,0};
        int ncol[4] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            ans[r][c] = dist;
            q.pop();

            for(int i = 0;i<4;i++)
            {
                int nr = r+nrow[i];
                int nc = c+ncol[i];
                while(nr >= 0 && nr < n && nc >=0 && nc<m  && vis[nr][nc]!=1)
                {
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},dist+1});
                }
            }
        }
        return ans;
    }
};