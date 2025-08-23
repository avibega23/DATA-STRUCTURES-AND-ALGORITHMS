// User function Template for C++

class Solution {
  public:
    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,vector<int>&time,vector<int>&minTime,vector<int>&ans,int & cnt)
    {
        vis[node] = 1;
        time[node] = minTime[node] = cnt++;
        int child = 0;
        for(auto it:adj[node])
        {
            if(it == parent) continue;
            if(!vis[it])
            {
                dfs(it,node,adj,vis,time,minTime,ans,cnt);
                minTime[node] = min(minTime[node],minTime[it]);
                if(time[node]<=minTime[it] && parent!=-1)
                {
                    ans[node] =1;
                }
                child++;
            }
            else
            {
                minTime[node] = min(minTime[node],time[it]);
            }
        }
        if(child>1 && parent == -1) ans[node] = 1; 
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans(V,0);
        int cnt = 0;
        vector<int>time(V,0),minTime(V,0),vis(V,0);
        dfs(0,-1,adj,vis,time,minTime,ans,cnt);
        vector<int>mark;
        for(int i = 0;i<V;i++)
        {
            if(ans[i]==1) mark.push_back(i);
        }
        if(mark.size()==0) return {-1};
        return mark;
    }
};