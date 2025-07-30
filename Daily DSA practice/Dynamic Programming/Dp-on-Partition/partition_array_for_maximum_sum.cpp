//https://leetcode.com/problems/partition-array-for-maximum-sum/description/
//recursion + memo + tabulation all in one 
class Solution {
public:
    int recurse(vector<int>&arr,int i,int x,vector<int>&dp)
    {
        int n = arr.size();
        if(i >= n) return 0;
        if(dp[i]!=-1) return dp[i];

        int maxi = INT_MIN;
        int maxiNum = INT_MIN;
        for(int k = i;k < x+i;k++)
        {
            if(k < n)
            {
                maxiNum = max(maxiNum,arr[k]);
                maxi = max(maxi,((k-i+1)*maxiNum)+recurse(arr,k+1,x,dp));
            }
            
        }
        return dp[i] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int x){
        int n = arr.size();
        vector<int>dp(n+1,0); 

        for(int i = n-1;i>=0;i--)
        {
            int maxi = INT_MIN;
            int maxiNum = INT_MIN;
            for(int k = i;k < x+i;k++)
            {
                if(k < n)
                {
                    maxiNum = max(maxiNum,arr[k]);
                    maxi = max(maxi,((k-i+1)*maxiNum)+dp[k+1]);
                }
            }
            dp[i] = maxi;
        }
        return dp[0];
    }
};


