class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&ans)
    {
        if(vis[node]==1) return false;
        if(vis[node]==2) return true;
        vis[node] = 1;
        for(auto it:graph[node])
        {
            if(!dfs(it,graph,vis,ans))
            {
                return false;
            }
        }
        vis[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),0);
        vector<int>ans;
        for(int i = 0;i<graph.size();i++)
        {
            if(dfs(i,graph,vis,ans))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};