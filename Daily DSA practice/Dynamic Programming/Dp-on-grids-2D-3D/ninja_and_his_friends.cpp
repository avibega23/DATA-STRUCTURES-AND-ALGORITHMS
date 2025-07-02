//memoization approach
#include <bits/stdc++.h> 
int recurse(vector<vector<int>>&grid,int i,int j1,int j2,int r,int c,vector<vector<vector<int>>>&dp)
{
    if(j1<0 || j1 >=c || j2 < 0 || j2 >= c) return -1e9;
    if(i == r-1)
    {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)
    {
        return dp[i][j1][j2];
    }
    

    int maxi = INT_MIN;
    for(int a  = -1;a < 2;a++)
    {
        for(int b = -1;b<2;b++)
        {
            int ans;
            if(j1 == j2)
            {
                ans = grid[i][j1] + recurse(grid,i+1,j1+a,j2+b,r,c,dp);
            }
            else
            {
                ans = grid[i][j1] + grid[i][j2] + recurse(grid,i+1,j1+a,j2+b,r,c,dp);
            }
            maxi = max(ans,maxi);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return recurse(grid,0,0,c-1,r,c,dp);
    
}


//tabulated approach

#include <bits/stdc++.h> 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    for(int i = r-1;i>=0;i--)
    {
        for(int j1 = 0;j1<c;j1++)
        {
            for(int j2 = 0;j2<c;j2++)
            {
                if(i == r-1)
                {
                    if(j1 == j2) dp[i][j1][j2] = grid[i][j1];
                    else dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                    continue;
                }

                int maxi = INT_MIN;

                for(int d1 = -1;d1<2;d1++)
                {
                    for(int d2 = -1;d2 < 2;d2++)
                    {
                        int nj1 = d1+j1;
                        int nj2 = d2+j2;

                        int ans;
                        if(nj1 >=0 && nj1 < c && nj2 >= 0 && nj2 < c)
                        {
                            if(j1 == j2) ans = grid[i][j1] + dp[i+1][j1+d1][j2+d2];
                            else ans = grid[i][j1] + grid[i][j2] + dp[i+1][j1+d1][j2+d2];

                            maxi = max(ans,maxi);
                        }
                        
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c-1];
    
}