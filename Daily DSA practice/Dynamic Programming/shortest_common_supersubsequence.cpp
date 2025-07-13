class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int ind1 = text1.size() , ind2 = text2.size();
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for (int i = 1; i <= ind1; i++) {
            for (int j = 1; j <= ind2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
    string ans = "";
	while(ind1>0 && ind2>0)
	{
		if(text1[ind1 - 1] == text2[ind2 - 1])
		{
			ans.push_back(text1[ind1-1]);
			ind1--;
			ind2--;
		}
		else
		{
			if(dp[ind1-1][ind2]>dp[ind1][ind2-1])
			{
                ans.push_back(text1[ind1-1]);
				ind1--;
			}
			else
            {
                ans.push_back(text2[ind2-1]);
                ind2--;
            } 
		}
	}
    while(ind1>0)
    {
        ans.push_back(text1[ind1-1]);
        ind1--;
    } 
    while(ind2>0)
    {
        ans.push_back(text2[ind2-1]);
        ind2--;
    } 
	reverse(ans.begin(),ans.end());
	return ans;
    }
};
