class Solution {
public:
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        vector<vector<int>>adj(n);
        int cnt = 0;
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>time(n,0),minTime(n,INT_MAX),vis(n,0);
        dfs(0,0,adj,vis,time,minTime,ans,cnt);
        return ans;
    }
};