class Solution {
public:
    struct compare{
        bool operator()(pair<int,int>p1,pair<int,int>p2)
        {
            return p1.second<p2.second;
        }
    };
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(int i = 0;i<score.size();i++)
        {
            pq.push({i,score[i]});
        }
        int cnt = 0;
        vector<string>ans(score.size());
        while(!pq.empty())
        {
            cnt++;
            if(cnt == 1 ) ans[pq.top().first] = "Gold Medal";
            else if(cnt ==2) ans[pq.top().first] = "Silver Medal";
            else if(cnt == 3) ans[pq.top().first] = "Bronze Medal";
            else
            {
                ans[pq.top().first] = to_string(cnt);
            }
            pq.pop();
        }
        return ans;
    }
};