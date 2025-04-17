class Solution {
    public:
        // static bool cmp(vector<int>a1,vector<int>a2)
        // {
        //     return (a1[0]==a2[0])?a1[1]<=a2[1]:a1[0]<a2[0];
        // }
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(),intervals.end());
            vector<vector<int>>ans;
            int index = -1;
        
            for(int i = 0;i<intervals.size();i++)
            {
                int start = intervals[i][0];
                int end = intervals[i][1];
    
                if(ans.empty())
                {
                    ans.push_back({start,end});
                    continue;
                }
    
                if(start<=ans.back()[1])
                {
                    start = ans.back()[0];
                    end = max(end,ans.back()[1]);
                    ans.pop_back();
                }
    
                ans.push_back({start,end});
            }
            return ans;
        }
    };