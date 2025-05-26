class Solution {
public:
    struct compare{
        bool operator()(pair<int,int>p1,pair<int,int>p2){
            return p1.second < p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it:nums)
        {
            mpp[it]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(auto it:mpp)
        {
            pq.push(it);
        }
        vector<int>ans;
        while(k--)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};