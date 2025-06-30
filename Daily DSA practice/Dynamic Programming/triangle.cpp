//recursive solution
class Solution {
public:
    int recurse(vector<vector<int>>&triangle,int i,int j)
    {
        int m = triangle.size();
        if(i == m) return 0;
        int n = triangle[i].size();
        if(j > n-1) return 1e9;
        
        
        int plusZero = triangle[i][j] + recurse(triangle,i+1,j);
        int plusOne = triangle[i][j] + recurse(triangle,i+1,j+1);

        return min(plusZero,plusOne);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return recurse(triangle,0,0);
    }
};

//memoization solution
class Solution {
public:
    int recurse(vector<vector<int>>&triangle,int i,int j,vector<vector<int>>&dp)
    {
        int m = triangle.size();
        if(i == m) return 0;
        int n = triangle[i].size();
        if(j > n-1) return 1e9;

        if(dp[i][j]!=-1) return dp[i][j];
        
        
        int plusZero = triangle[i][j] + recurse(triangle,i+1,j,dp);
        int plusOne = triangle[i][j] + recurse(triangle,i+1,j+1,dp);

        return dp[i][j] = min(plusZero,plusOne);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), -1));

        return recurse(triangle,0,0,dp);
    }
};


//tabulated solution
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), -1));
        for(int i = 0;i<n;i++)
        {
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i = n-2;i>=0;i--)
        {
            for(int j = i;j >= 0;j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int right = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,right);
            }
        }
        return dp[0][0];
    }
};


//space optimized solution
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        for(int i = 0;i<n;i++)
        {
            dp[i] = triangle[n-1][i];
        }

        for(int i = n-2;i>=0;i--)
        {
            vector<int>temp(n);
            for(int j = i;j >= 0;j--)
            {
                int down = triangle[i][j] + dp[j];
                int right = triangle[i][j] + dp[j+1];

                temp[j] = min(down,right);
            }
            dp = temp;
        }
        return dp[0];
    }
};