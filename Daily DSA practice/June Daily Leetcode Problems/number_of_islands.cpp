// User function Template for C++
class DisjointSet {
    public:
    unordered_map<int, int> parent, size;

    int findPar(int node) {
        if (parent.find(node) == parent.end())
            return parent[node] = node;
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if (ult_u == ult_v) return;
        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int nRow[4] = {0,1,0,-1};
        int nCol[4] = {1,0,-1,0};
        vector<int>ans;
        int cnt  = 0;
        for(auto it:operators)
        {
            int r = it[0];
            int c = it[1];
            if(vis[r][c]) 
            {
                ans.push_back(cnt);
                continue;
            }
            vis[r][c] = 1;
            cnt++;
            int id = (r*m)+c;
            for(int i = 0 ;i<4;i++)
            {
                int nr = r+nRow[i];
                int nc = c+nCol[i];
                if(nr>=0 && nr < n && nc >=0 && nc < m && vis[nr][nc])
                {
                    int thisId = nr * m + nc;
                    if(ds.findPar(thisId)!=ds.findPar(id))
                    {
                        cnt--;
                        ds.unionBySize(thisId,id);
                    }
                }
            }
            ans.push_back(cnt);
            
        }
        return ans;
    }
};
