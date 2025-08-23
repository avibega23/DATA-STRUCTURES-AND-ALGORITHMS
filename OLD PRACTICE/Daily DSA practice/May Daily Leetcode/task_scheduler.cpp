class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        unordered_map<char,int>mpp;
        for(auto it:tasks)
        {
            mpp[it]++;
        }
        for(auto it:mpp)
        {
            pq.push(it.second);
        }
        int time = 0;
        while(!pq.empty()||!q.empty())
        {
            time++;
            if(!pq.empty())
            {
                int top = pq.top(); pq.pop();
                top--;
                if(top != 0)
                {
                    q.push({time+n,top});
                }
            }
            if(!q.empty() && q.front().first == time)
            {
                pq.push(q.front().second);
                q.pop();
            }
        }
        return time;

    }
};