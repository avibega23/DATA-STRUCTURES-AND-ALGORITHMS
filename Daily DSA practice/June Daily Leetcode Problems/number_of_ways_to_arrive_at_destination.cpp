class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i = 0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        int mode = 1e9+7;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>pq;
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        pq.push({0,0});
        ways[0] = 1;
        dist[0] = 0;
        while(!pq.empty())
        {
            auto [time,node] = pq.top(); pq.pop();

            if(time>dist[node])  continue;

            for(auto [v,wt]:adj[node])
            {
                if(dist[v]>wt+time)
                {
                    dist[v] = wt+time;
                    ways[v] = ways[node];
                    pq.push({dist[v],v});
                }
                else if(dist[v]==wt+time)
                {
                    ways[v] = (ways[v]+ways[node])%mode;
                }
            }

        }
        return ways[n-1]%mode;
    }
};