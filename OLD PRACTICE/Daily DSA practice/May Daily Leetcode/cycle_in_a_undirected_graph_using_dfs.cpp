class Solution {
  public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,int index,int parent)
    {
        vis[index] =1;
        for(auto it:adj[index])
        {
            if(vis[it]!=1)
            {
                if(dfs(adj,vis,it,index))return true;;
            }
            else if(it != parent)
            {
                return true;
            }
        }
        return false;
    }
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
            if(!vis[i] && dfs(adj,vis,i,-1))
            {
                return true;
            }
        }
        return false;
    }
};