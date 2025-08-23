// User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int>vis(leaves+1,0);
        unordered_set<int>frog;
        for(int i =0;i<N;i++)
        {
            if(frog.find(frogs[i])!=frog.end()||frogs[i]==0) continue;
            int st = frogs[i];
            frog.insert(st);
            int j = 0;
            while(j <= leaves)
            {
                int multi = st * j;
                if(multi > leaves) break;
                if(!vis[multi]) vis[multi] = 1;
                j++;
            }
        }
        int cnt = 0;
        for(int i = 0;i<vis.size();i++)
        {
            if(!vis[i]) cnt++;
        }
        return cnt;
    }
};
