class Solution {
    public:
        vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
            unordered_map<int,vector<int>>mpp;
            vector<vector<int>>ans;
            for(int i = 0;i<groupSizes.size();i++)
            {
                mpp[groupSizes[i]].push_back(i);
    
                if(mpp[groupSizes[i]].size()==groupSizes[i])
                {
                    ans.push_back(mpp[groupSizes[i]]);
                    mpp.erase(groupSizes[i]);
                }
            }
            return ans;
        }
    };