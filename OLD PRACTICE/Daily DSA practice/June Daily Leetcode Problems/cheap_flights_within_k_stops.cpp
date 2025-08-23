class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>stops(n,INT_MAX);
        pq.push({0,{src,0}});

        while(!pq.empty())
        {
            int price = pq.top().first;
            int from = pq.top().second.first;
            int steps = pq.top().second.second;
            pq.pop();

            if(from == dst) return price;
            if(steps > k || steps > stops[from]) continue;
            stops[from] = steps;

            for(auto it:adj[from])
            {
                    pq.push({price+it.second,{it.first,steps+1}});
            }
        }
        return -1;
    }
};