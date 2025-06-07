// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        queue<int>q;
        vector<int>dist(V,1e9);
        dist[0] = 0;
        q.push(0);
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            for(auto it:adj[top])
            {
                if(dist[top]+it.second < dist[it.first])
                {
                    dist[it.first] = dist[top]+it.second;
                    q.push(it.first);
                }
            }
        }
        for(int i = 0;i<dist.size();i++)
        {
            if(dist[i]==1e9)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
