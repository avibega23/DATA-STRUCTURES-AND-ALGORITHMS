class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        queue<int>q;
        vector<int>dist(adj.size(),1e9);
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            
            for(auto it:adj[top])
            {
                if(dist[top]+1<dist[it])
                {
                    dist[it] = dist[top]+1;
                    q.push(it);
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