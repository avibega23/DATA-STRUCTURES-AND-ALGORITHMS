class Solution {
    public:
        string findCommonResponse(vector<vector<string>>& responses) {
            unordered_map<string,int>mpp;
            for(int i = 0;i<responses.size();i++)
                {
                    unordered_map<string,int>mpp1;
                    for(int j = 0;j<responses[i].size();j++)
                        {
                            mpp1[responses[i][j]]++;
                        }
                    for(auto it:mpp1)
                        {
                            mpp[it.first]++;
                        }
                }
            int maxi = INT_MIN;
            string ans = "";
            for(auto it:mpp)
                {
                    if(it.second>maxi)
                    {
                        maxi = it.second;
                        ans = it.first;
                    }
                    if(it.second == maxi)
                    {
                        if(it.first.size()>ans.size())
                        {
                            for(int i = 0;i<it.first.size();i++)
                                {
                                    if(it.first[i]<ans[i])
                                    {
                                        ans = it.first;
                                        break;
                                    }
                                    else if(ans[i]<it.first[i])
                                    {
                                        break;
                                    }
                                }
                        }
                        else
                        {
                            for(int i = 0;i<ans.size();i++)
                                {
                                    if(it.first[i]<ans[i])
                                    {
                                        ans = it.first;
                                        break;
                                    }
                                    else if(ans[i]<it.first[i])
                                    {
                                        break;
                                    }
                                }
                        }
                    }
                }
            return ans;
        }
    };©leetcode