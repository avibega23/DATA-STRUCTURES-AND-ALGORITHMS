//https://leetcode.com/problems/burst-balloons/submissions/1714223823/

//tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i = n;i>=1;i--)
        {
            for(int j = 1;j<=n;j++)
            {
                if(i > j) continue;
                int maxi = INT_MIN;
                for( int k = i ; k<=j ; k++ )
                {
                    maxi = max(maxi,(nums[i-1]*nums[k]*nums[j+1]) + dp[i][k-1]+ dp[k+1][j]);
                    
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};

//recursion+memo

class Solution {
public:
    int recurse(vector<int>&nums,int i,int j,vector<vector<int>>&dp)
    {
        int n = nums.size();
        if(i > j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for( int k = i ; k<=j ; k++ )
        {
            maxi = max(maxi,(nums[i-1]*nums[k]*nums[j+1]) + recurse(nums,i,k-1,dp) + recurse(nums,k+1,j,dp));
            
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return recurse(nums,1,n-2,dp);
    }
};

