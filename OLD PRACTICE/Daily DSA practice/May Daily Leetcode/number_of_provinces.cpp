class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>&vis,int index)
    {
        vis[index] = 1;
        for(int j = 0;j<isConnected.size();j++)
        {
            if(index != j && isConnected[index][j]==1 && !vis[j])
            {
                dfs(isConnected,vis,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n,0);
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(isConnected,vis,i);
            }
        }
        return cnt;
    }
};