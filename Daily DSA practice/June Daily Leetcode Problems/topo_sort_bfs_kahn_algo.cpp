class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        queue<int>q;
        unordered_map<int,int>indegree;
        vector<vector<int>>adj(V);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        for(int i = 0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto it:adj[top])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};