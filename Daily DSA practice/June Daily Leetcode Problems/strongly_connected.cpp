//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(vector<vector<int>>&adj,int index,stack<int>&st,vector<int>&vis)
    {
        vis[index] = 1;
        for(auto it:adj[index])
        {
            if(!vis[it])
            {
                dfs(adj,it,st,vis);
            }
        }
        st.push(index);
    }
    void dfs(vector<vector<int>>&adj,int index,vector<int>&vis)
    {
        vis[index] = 1;
        for(auto it:adj[index])
        {
            if(!vis[it])
            {
                dfs(adj,it,vis);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>vis(n,0);
        stack<int>st;
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,i,st,vis);
            }
        }
        vector<vector<int>>adjT(n);
        for(int i = 0;i<n;i++)
        {
            vis[i] = 0;
            for(auto it:adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while(!st.empty())
        {
            int node = st.top();st.pop();
            if(!vis[node])
            {
                dfs(adjT,node,vis);
                scc++;
            }
        }
        return scc;
    }
};