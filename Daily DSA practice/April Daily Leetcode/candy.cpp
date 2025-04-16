class Solution {
    public:
        int candy(vector<int>& ratings) {
            vector<int>ans(ratings.size(),0);
    
            for(int i = 0;i<ratings.size();i++)
            {
                if(i == 0) ans[i] = 1;
                else
                {
                    if(ratings[i]>ratings[i-1])
                    {
                        ans[i] = ans[i-1]+1;
                    }
                    else
                    {
                        ans[i] = 1;
                    }
                }
            }
    
            for(int i = ratings.size()-1;i>=0;i--)
            {
                if(i == ratings.size()-1 && ans[i]==0) ans[i] = 1;
                else
                {
                    if(i+1>=ratings.size())continue;
                    else if(ratings[i]>ratings[i+1] && ans[i]<=ans[i+1])
                    {
                        ans[i] = ans[i+1]+1;
                    }
                }
            }
            int sum = 0;
            for(auto it:ans)
            {
                sum += it;
            }
            return sum;
        }
    };