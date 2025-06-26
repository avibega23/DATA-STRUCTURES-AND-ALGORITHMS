class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&vis,vector<int>&time,vector<int>&minTime,vector<vector<int>>&ans,int & cnt)
    {
        vis[node] = 1;
        time[node] = minTime[node] = cnt++;

        for(auto it:adj[node])
        {
            if(it == parent) continue;
            if(!vis[it])
            {
                dfs(it,node,adj,vis,time,minTime,ans,cnt);
                minTime[node] = min(minTime[node],minTime[it]);
                if(time[node]<minTime[it])
                {
                    ans.push_back({node,it});
                }
            }
            else
            {
                minTime[node] = min(minTime[node],time[it]);
            }
        }
    }
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