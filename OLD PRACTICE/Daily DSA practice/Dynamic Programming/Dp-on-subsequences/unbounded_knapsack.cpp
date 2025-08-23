//recursion + memoization
class Solution {
  public:
    int recurse(vector<int>&val,vector<int>&wt,int capacity,int ind,vector<vector<int>>&dp)
    {
        if(ind == 0 )
        {
            return (capacity/wt[0]) * val[0] ;
        }
        if(dp[ind][capacity]!=-1) return dp[ind][capacity];
        int take = 0;
        if(capacity >= wt[ind])
        take = val[ind] + recurse(val,wt,capacity-wt[ind],ind,dp);
        int nonTake =recurse(val,wt,capacity,ind-1,dp);
        
        return dp[ind][capacity] = max(take,nonTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>>dp(val.size(),vector<int>(capacity+1,-1));
        return recurse(val,wt,capacity,val.size()-1,dp);
    }
};

//tabulation solution
// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>>dp(val.size(),vector<int>(capacity+1,-1));
        for(int i = 0;i<capacity+1;i++)
        {
            dp[0][i] = (i/wt[0])*val[0];
        }
        for(int i = 1;i<val.size();i++)
        {
            for(int w = 0;w<capacity+1;w++)
            {
                int notTake = dp[i-1][w];
                int take = 0;
                if(wt[i]<=w)
                take = val[i] + dp[i][w-wt[i]];
                
                dp[i][w] = max(take,notTake);
                
            }
        }
        return dp[val.size()-1][capacity];
    }
};