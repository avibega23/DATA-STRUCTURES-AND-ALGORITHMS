//https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

//recursion + memoization
class Solution {
  public:
    int recurse(vector<int>&arr,int i,int j,vector<vector<int>>&dp)
    {
        if(i == j) return 0;
        int mini = INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k = i;k<j;k++)
        {
            int steps = (arr[i-1] * arr[k] * arr[j] ) +  recurse(arr,i,k,dp) + recurse(arr,k+1,j,dp);
            mini = min(mini,steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        return recurse(arr,1,arr.size()-1,dp);
    }
};

//tabulation
class Solution {
  public:

    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        int dp[n][n];
        for(int i = 0;i<n;i++)
        {
            dp[i][i] = 0;
        }
        for(int i = n-1;i>=1;i--)
        {
            for(int j = i+1;j<n;j++)
            {
                int mini = INT_MAX;
                for(int k = i;k<j;k++)
                {
                    int steps = (arr[i-1] * arr[k] * arr[j] ) +  dp[i][k] + dp[k+1][j] ;
                    mini = min(mini,steps);
                }
                dp[i][j] = mini; 
            }
        }
        
        
        return dp[1][n-1];
    }
};
