//recursive solution TLE
class Solution {


public:
    int recurse(int i,int j,vector<vector<int>>&grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1 && j == n-1) return grid[i][j];
        if(i > m-1 || j > n-1) return 1e9;

        int down = grid[i][j] + recurse(i+1,j,grid);
        int right = grid[i][j] + recurse(i,j+1,grid);


        return min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        return recurse(0,0,grid);
    }
};

//tabulated approach 
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if(i>0)  up += dp[i-1][j];
                    else up += 1e9;

                    int left = grid[i][j];

                    if(j>0) left += dp[i][j-1];
                    else left += 1e9; 
                    dp[i][j] = min(up,left);
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};


//tabulated + space optimized 
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>dp(n,-1);
        
        for(int i = 0;i<m;i++)
        {
            vector<int>temp(n,-1);
            for(int j = 0;j<n;j++)
            {
                if(i == 0 && j == 0) temp[j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if(i>0)  up += dp[j];
                    else up += 1e9;

                    int left = grid[i][j];

                    if(j>0) left += temp[j-1];
                    else left += 1e9; 
                    temp[j] = min(up,left);
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};


