class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int rArr[4] = {0,1,0,-1};
        int cArr[4] = {1,0,-1,0};
        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            int wt = it.first;
            if(r == n-1 && c == m-1)
            {
                return wt;
            }
            for(int i = 0;i<4;i++)
            {
                int nr = r + rArr[i];
                int nc = c + cArr[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int newEffort = max(wt, abs(heights[nr][nc] - heights[r][c]));
                    if(newEffort < dist[nr][nc])
                    {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};