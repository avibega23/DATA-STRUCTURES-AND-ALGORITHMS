class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        unordered_map<int,int>indegree;
        for(auto it:prerequisites)
        {
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }

        queue<int>q;
        for(int i = 0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int top = q.front();
            q.pop();

            ans.push_back(top);

            for(auto it:adj[top])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return (ans.size()==numCourses);
    }
};