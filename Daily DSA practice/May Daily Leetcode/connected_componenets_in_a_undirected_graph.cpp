
class Solution {
  public:
    vector<int> dfs(vector<vector<int>>&adj,set<int>&vis,int i,vector<int>&stepAns)
    {
        vis.insert(i);
        stepAns.push_back(i);
        
        for(int j = 0;j<adj[i].size();j++)
        {
            if(vis.find(adj[i][j])==vis.end())
            {
                dfs(adj,vis,adj[i][j],stepAns);
            }
        }
        return stepAns;
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        set<int>vis;
        vector<vector<int>>ans;
        for(int i = 0;i<V;i++)
        {
            if(vis.find(i)==vis.end())
            {
                vector<int>stepAns;
                dfs(adj,vis,i,stepAns);
                ans.push_back(stepAns);
            }
        }
        return ans;
    }
};
