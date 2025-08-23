// User function Template for C++
class Solution {
  public:
    class DisjointSet{
    private:
        vector<int>rank;
        vector<int>size;
        vector<int>parent;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i = 0;i<=n;i++)
            {
                parent[i] = i;
            }
            size.resize(n+1,1);
        }
        int findPar(int node)
        {
            if(parent[node]==node)
            {
                return node;
            }
            return parent[node] = findPar(parent[node]);
        }
        void unionByRank(int u,int v)
        {
            int ult_u = findPar(u);
            int ult_v = findPar(v);

            if(rank[ult_u]<rank[ult_v])
            {
                parent[ult_u] = ult_v;
            }
            else if(rank[ult_u]>rank[ult_v])
            {
                parent[ult_v] = ult_u;
            }
            else{
               parent[ult_v] = ult_u;
               rank[ult_u]++; 
            }
        }
        void unionBySize(int u,int v)
        {
            int ult_u = findPar(u);
            int ult_v = findPar(v);

            if(size[ult_u]<size[ult_v])
            {
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            else
            {
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
        }
};
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,pair<int,int>>>nums;
        for(auto it:edges)
        {
            int wt = it[2];
            int u = it[0];
            int v = it[1];
            nums.push_back({wt,{u,v}});
        }
        sort(nums.begin(),nums.end());
        DisjointSet ds(V);
        int uwt = 0;
        for(auto it:nums)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findPar(u)!=ds.findPar(v))
            {
                uwt += wt;
                ds.unionBySize(u,v);
            }
        }
        return uwt;
    }
};