class Solution {
public:
    int recurse(int m,int n,int i,int j,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];

        if(i == m-1 && j == n-1)
        {
            return 1;
        }

        int sum = 0;

        if(i+1 < m) sum += recurse(m,n,i+1,j,dp);

        if(j+1 < n) sum += recurse(m,n,i,j+1,dp);

        return dp[i][j] = sum;

    }
    int uniquePaths(int m, int n) {

        vector<int>prev(n,0);
        
        for(int i = 0; i < m; i++)
        {
            vector<int>temp(n,0);

            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;
                
                if(i > 0) up = prev[j];

                if(j > 0) left = temp[j-1];

                temp[j] = up + left;               
            }

            prev = temp;
        }

        return prev[n-1];
    }
};