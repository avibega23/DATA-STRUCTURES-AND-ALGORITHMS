class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&col,int node,int color)
    {
        col[node] = color;

        for(auto it:graph[node])
        {
            if(col[it] == -1)
            {
                if(dfs(graph,col,it,!color)==false) return false;
            }
            else if(col[it]==color) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>col(graph.size(),-1);

        for(int i = 0;i<graph.size();i++)
        {
            if(col[i]==-1)
            {
                if(dfs(graph,col,i,0)==false) return false;
            }
        }
        return true;
    }
};