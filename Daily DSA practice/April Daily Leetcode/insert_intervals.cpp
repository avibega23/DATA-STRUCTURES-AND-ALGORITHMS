class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>>ans;
            int i = 0;
            int n = intervals.size();
            if(n==0) return {newInterval};
            while(i < n && intervals[i][1] < newInterval[0])
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
                i++;
            }
            if(i>=n)
            {
                ans.push_back(newInterval);
                return ans;
            }
            int start = min(newInterval[0],intervals[i][0]);
            int end = newInterval[1];
            while(i < n && intervals[i][0] <= newInterval[1])
            {
                end = max(intervals[i][1],end);
                i++;
            }
            ans.push_back({start,end});
            while(i<n)
            {
                ans.push_back(intervals[i]);
                i++;
            }
            return ans;
        
        }
        
    };