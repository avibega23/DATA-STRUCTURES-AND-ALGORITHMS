class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i = 0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1);
        for(int i = 0;i<parent.size();i++)
        {
            parent[i] = i;
        }
        pq.push({0,1});
        dist[1] = 0;
        while(!pq.empty())
        {
            int d = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            
            if(d > dist[v]) continue;
            
            for(auto it:adj[v])
            {
                int nd = it.first;
                int nv = it.second;
                
                if(dist[v]+nd < dist[nv])
                {
                    dist[nv] =dist[v]+nd;
                    pq.push({dist[nv],nv});
                    parent[nv] = v;
                }
            }
        }
        if(dist[n]==INT_MAX)
        return {-1};
        vector<int>ans;
        ans.push_back(dist[n]);
        int i = n;
        while(i!=parent[i])
        {
            ans.push_back(i);
            i = parent[i];
        }
        ans.push_back(1);
        reverse(ans.begin()+1,ans.end());
        return ans;
    }
};