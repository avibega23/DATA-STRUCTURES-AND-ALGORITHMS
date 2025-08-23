class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> nums[]) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        vector<int>vis(V,0);
        int sum = 0;
        while(!pq.empty())
        {
            auto top = pq.top(); pq.pop();
            int wt = top.first;
            int node = top.second;
            
            if(vis[node]) continue;
            
            vis[node]=1;
            sum += wt;
            
            for(auto it:nums[node])
            {
                int nwt = it[1];
                int nnode = it[0];
                
                if(!vis[nnode])
                {
                    pq.push({nwt,nnode});
                }
            }
        }
        return sum;
    }
};