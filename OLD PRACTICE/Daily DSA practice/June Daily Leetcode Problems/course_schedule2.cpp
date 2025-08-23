class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,int i,vector<int>&ans,vector<int>&path)
    {
        vis[i] = 1;
        path[i] = 1;
        for(auto it:adj[i])
        {
            if(!vis[it] && !dfs(adj,vis,it,ans,path)) return false;
            else if(path[it]) return false;
        }
        path[i] = 0;
        ans.push_back(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>mat(numCourses);
        vector<int>ans;
        vector<int>path(numCourses,0);
        for(int i = 0 ;i<prerequisites.size();i++)
        {
            mat[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>vis(numCourses,0);
        for(int i =0;i<numCourses;i++)
        {
            if(!vis[i] && !dfs(mat,vis,i,ans,path))
                return {};
                
        }
        return ans;
    }
};