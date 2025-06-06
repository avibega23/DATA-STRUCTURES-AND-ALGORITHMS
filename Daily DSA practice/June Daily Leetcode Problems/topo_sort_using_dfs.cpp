class Solution {
  public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&edges,vector<int>&ans)
    {
        vis[node] = 1;
        for(auto it:edges[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,edges,ans);
            }
        }
        ans.push_back(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>ans;
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,ans);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};