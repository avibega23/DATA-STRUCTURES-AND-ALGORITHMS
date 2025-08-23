class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i = 0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dist(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty())
        {
            auto [time,node] = pq.top(); pq.pop();

            for(auto it:adj[node])
            {
                if(time+it.second < dist[it.first])
                {
                    pq.push({time+it.second,it.first});
                    dist[it.first] = time+it.second;
                }
            }
        }
        int maxTime = INT_MIN;
        for(int i = 1;i<dist.size();i++)
        {
            if(dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime,dist[i]);
            
        }
        return maxTime;
    }
};