class DisjointSet {
    public:
    unordered_map<int, int> parent, size;

    int findPar(int node) {
        if (parent.find(node) == parent.end())
        {
            size[node] = 1;
            return parent[node] = node;
        }
            
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
    int largestIsland(vector<vector<int>>& grid) {
        DisjointSet ds;
        int n = grid.size();
        int m = grid[0].size();
        int nRow[4] = {0,1,0,-1};
        int nCol[4] = {1,0,-1,0};
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int id = (m*i)+j;
                ds.findPar(id);
                if(grid[i][j]==1)
                {
                    for(int k = 0;k<4;k++)
                    {
                        int nr = i+nRow[k];
                        int nc = j+nCol[k];
                        if(nr>=0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]==1)
                        {
                            
                            int adjId = (m*nr)+nc;
                             ds.findPar(adjId);
                            ds.unionBySize(id,adjId);
                        }
                    }
                }
            }
        }
        int maxVal = 0;
        bool hasZero = false;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    hasZero = true;
                    int cnt = 1;
                    unordered_set<int> uniqueIslands;
                    for(int k = 0;k<4;k++)
                    {
                        int nr = i + nRow[k];
                        int nc = j + nCol[k];
                        if(nr >=0 && nr < n && nc >= 0 && nc <m && grid[nr][nc]==1)
                        {
                            int id = (nr*m)+nc;
                            id = ds.findPar(id);
                             if (uniqueIslands.find(id) == uniqueIslands.end()) {
                                cnt += ds.size[id];
                                uniqueIslands.insert(id);
                            }  
                        }
                    }
                    maxVal = max(maxVal,cnt);
                }
            }
        }
        if(!hasZero)
        {
            for(auto it:ds.size)
            {
                maxVal = max(maxVal,it.second);
            }
        }
        return maxVal;
    }
};