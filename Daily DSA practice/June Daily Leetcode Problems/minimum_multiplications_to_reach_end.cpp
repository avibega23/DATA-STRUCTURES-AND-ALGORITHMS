// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        q.push({start,0});
        if(start ==end) return 0;
        vector<int>dist(100000,1e9+7);
        dist[start] = 0;
        int mod = 100000;
        while(!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second; q.pop();
            
            for(auto it:arr)
            {
                int num = (it*node)% mod;
                if(steps+1 < dist[num])
                {
                    dist[num] = steps+1;
                    if(num == end) return steps+1;
                    q.push({num,steps+1});
                }
            }
        }
        return -1;
    }
};
