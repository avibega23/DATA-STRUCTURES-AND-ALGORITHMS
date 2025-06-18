#include<bits/stdc++.h>
using namespace std;

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