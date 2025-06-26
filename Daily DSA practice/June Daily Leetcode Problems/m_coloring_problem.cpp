class Solution {
  public:
    public:
    bool isSafe(int node, vector<int>& color, vector<vector<int>>& adj, int n, int col) {
        for (auto it : adj[node]) {
            if (color[it] == col) return false;
        }
        return true;
    }

    bool solve(int node, vector<int>& color, vector<vector<int>>& adj, int m, int n) {
        if (node == n) return true;

        for (int c = 1; c <= m; c++) {
            if (isSafe(node, color, adj, n, c)) {
                color[node] = c;
                if (solve(node + 1, color, adj, m, n)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
         vector<vector<int>> adj(v);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> color(v, 0);
        return solve(0, color, adj, m, v);
    }
};