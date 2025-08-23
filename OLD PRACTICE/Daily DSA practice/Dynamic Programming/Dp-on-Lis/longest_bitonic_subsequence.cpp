//https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1


class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp(n, 1);
        vector<int>dp2(n,1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        for (int i = n-1; i >=0; i--) {
            for (int j = n-1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        // for(int i = 0;i<n;i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << '\n';
        // for(int i = 0;i<n;i++)
        // {
        //     cout << dp2[i] << " ";
        // }
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {
            if(dp[i]!=1 && dp2[i]!=1)
            maxi  = max(maxi,dp[i]+dp2[i]-1);
        }
        return maxi;
    }
};

