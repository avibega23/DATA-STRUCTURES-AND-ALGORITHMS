class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>>adj(V);
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                queue<pair<int,int>>q;
                q.push({i,-1});
                vis[i] = 1;
                while(!q.empty())
                {
                    auto top = q.front(); q.pop();
                    int prev = top.second;
                    int cur = top.first;
                    for(auto it:adj[cur])
                    {
                        if(it!=prev)
                        {
                            if(vis[it]) return true;
                            q.push({it,cur});
                            vis[it] =1;
                        }
                    }
                }
            }
        }
        return false;
    }
};