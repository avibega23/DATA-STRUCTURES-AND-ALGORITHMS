class Solution {
  public:
    int longestCommonSubstr(string& text1, string& text2) {
        // your code here
        int ind1 = text1.size() , ind2 = text2.size();
        int maxi = 0;
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for (int i = 1; i <= ind1; i++) {
            for (int j = 1; j <= ind2; j++) {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxi = max(maxi,dp[i][j]);
                }
                    
            }
        }
        return maxi;
    }
};
