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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds;
        unordered_map<string,int>mpp;
        int n = accounts.size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                if(mpp.find(accounts[i][j])==mpp.end())
                {
                    mpp[accounts[i][j]] = i;
                }
                else
                {
                    ds.unionBySize(i,mpp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>>mergedMail(n);
        for(auto it:mpp)
        {
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i = 0;i<n;i++)
        {
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(int j = 0;j<mergedMail[i].size();j++)
            {
                temp.push_back(mergedMail[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};