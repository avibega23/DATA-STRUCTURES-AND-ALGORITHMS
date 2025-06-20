class DisjointSet {
    public:
    unordered_map<int, int> parent, size;

    int findPar(int node) {
        if (parent.find(node) == parent.end())
            return parent[node] = node;
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if (ult_u == ult_v) return;
        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = -1;
        int maxCol = -1;
        for(auto it:stones)
        {
            int u = it[0];
            int v = it[1];
            maxRow = max(u,maxRow);
            maxCol = max(v,maxCol);
        }
        DisjointSet ds;
        unordered_set<int>st;
        for(auto it:stones)
        {
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u,v+maxRow+1);
            st.insert(u);
            st.insert(v+maxRow+1);
        }
        int cnt = 0;
        for(auto it:st) if(ds.findPar(it) == it) cnt++;
        return stones.size()-cnt;
    }
};