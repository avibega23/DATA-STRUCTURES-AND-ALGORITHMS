class Solution {
  public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&path)
    {
        vis[node] = 1;
        path[node] = 1;
        
        for(auto it:adj[node])
        {
            if(path[it]) return false;
            else if(!vis[it] && !dfs(it,adj,vis,path)) return false;
        }
        path[node] = 0;
        return true;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>path(V,0);
        vector<int>vis(V,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        for(int i= 0;i<V;i++)
        {
            if(!vis[i] && !dfs(i,adj,vis,path)) return true;
        }
        return false;
    }
};