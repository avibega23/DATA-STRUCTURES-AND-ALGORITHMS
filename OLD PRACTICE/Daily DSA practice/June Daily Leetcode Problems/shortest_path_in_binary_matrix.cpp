class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size();
        int m = grid[0].size();
        int start = grid[0][0];
        int end = grid[n-1][m-1];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({1,{0,0}});
        int rArr[8] = {1,0,-1,0,1,1,-1,-1};
        int cArr[8] = {0,1,0,-1,1,-1,-1,1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int wt = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == n-1 && c == m-1) return wt;
            for(int i = 0;i<8;i++)
            {
                int nRow = r + rArr[i];
                int nCol = c + cArr[i];

                if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 0)
                {
                    q.push({wt+1,{nRow,nCol}});
                    vis[nRow][nCol] = 1;
                }
            }
        }
        return -1;
    }
};