class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.size() , ind2 = text2.size();
        vector<int>dp(text2.size()+1,0);
        for (int i = 1; i <= ind1; i++) {
            vector<int>temp(text2.size()+1,0);
            for (int j = 1; j <= ind2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    temp[j] = 1 + dp[j - 1];
                else
                    temp[j] = max(dp[j], temp[j - 1]);
            }
            dp = temp;
        }
        
        return dp[ind2];
    }
};
