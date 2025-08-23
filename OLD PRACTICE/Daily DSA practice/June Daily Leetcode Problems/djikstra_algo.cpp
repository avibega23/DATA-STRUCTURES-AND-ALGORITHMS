
// using pq // User Function Template
class Solution {
  public:
    struct cmp{
        bool operator()(pair<int,int>p1,pair<int,int>p2){
            return p1.second > p2.second;
        }
    };
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        
        pq.push({src,0});
        while(!pq.empty())
        {
            int d = pq.top().second;
            int v = pq.top().first;
            pq.pop();
            if(d>dist[v]) continue;
            for(auto it:adj[v])
            {
                int w = it.second;
                int nv = it.first;
                
                if(dist[v]!=INT_MAX && dist[v]+w < dist[nv])
                {
                    dist[nv] = dist[v]+w;
                    pq.push({nv,dist[nv]});
                }
            }
        }
        return dist;
    }
};



//using sets


// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        set<pair<int,int>>st;
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        st.insert({0,src});
        
        while(!st.empty())
        {
            auto it = st.begin();
            int currDist = (*it).first;
            int val = (*it).second;
            st.erase(it);
            
            if(currDist > dist[val]) continue;
            
            for(auto it:adj[val])
            {
                int ndist = it.first;
                int nval = it.second;
                
                if(dist[val]!=INT_MAX && dist[val]+ndist < dist[nval])
                {
                    dist[nval] = dist[val]+ndist;
                    st.insert({dist[nval],nval});
                }
            }
        }
        return dist;
    }
};