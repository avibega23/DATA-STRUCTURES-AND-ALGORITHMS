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
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int cnt = 0;
        for(auto it:connections)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findPar(u)!=ds.findPar(v))
            {
                ds.unionBySize(u,v);
            }
            else cnt++;
        }
        int temp = 0;
        for(int i = 0;i<n;i++)
        {
            if(ds.findPar(i)==i)
            {
                temp++;
            }
        }
        int needed = temp - 1;
        if(cnt < needed) return -1;
        return needed;
    }
};