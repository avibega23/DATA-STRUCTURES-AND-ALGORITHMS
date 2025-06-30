
//tabulated solution
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix.size(),-1));
        int n = matrix.size();
        for(int i = 0;i<n;i++)
        {
            dp[n-1][i] = matrix[n-1][i];
        }
        
        for(int i = n-2;i>=0;i--)
        {
            for(int j =  n-1;j>=0;j--)
            {
                if(j == 0)
                {
                    dp[i][j] = min(matrix[i][j]+dp[i+1][j],matrix[i][j]+dp[i+1][j+1]);
                }
                else if(j == n-1)
                {
                    dp[i][j] = min(matrix[i][j]+dp[i+1][j],matrix[i][j]+dp[i+1][j-1]);
                }
                else
                {
                    dp[i][j] = min(matrix[i][j]+dp[i+1][j],min(matrix[i][j]+dp[i+1][j-1],matrix[i][j]+dp[i+1][j+1]));
                }
            }
        }
        int maxi = 0;
        for(int i =0;i<n;i++)
        {
            maxi = min(maxi,dp[0][i]);
        }
        return maxi;
    }
};



///tabulated + space optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>dp(n);
        for(int i = 0;i<n;i++)
        {
            dp[i] = matrix[n-1][i];
        }
        
        for(int i = n-2;i>=0;i--)
        {
            vector<int>temp(n);
            for(int j =  n-1;j>=0;j--)
            {
                if(j == 0)
                {
                    temp[j] = min(matrix[i][j]+dp[j],matrix[i][j]+dp[j+1]);
                }
                else if(j == n-1)
                {
                    temp[j] = min(matrix[i][j]+dp[j],matrix[i][j]+dp[j-1]);
                }
                else
                {
                    temp[j] = min(matrix[i][j]+dp[j],min(matrix[i][j]+dp[j-1],matrix[i][j]+dp[j+1]));
                }
            }
            dp = temp;
        }
        int mini = INT_MAX;
        for(int i =0;i<n;i++)
        {
            mini = min(mini,dp[i]);
        }
        return mini;
    }
};


