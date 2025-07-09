//recursion + memoization
int recurse(vector<int>&price,int n,int ind,vector<vector<int>>&dp)
{
	if(ind <= 0 || n == 0)
	{
		return 0;
	}
	if(dp[ind-1][n]!=-1) return dp[ind-1][n];
	int take = 0;
	if(ind<=n) take = price[ind-1] + recurse(price,n-ind,ind,dp);
	int nonTake = recurse(price,n,ind-1,dp);

	return dp[ind-1][n] = max(take,nonTake); 
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return recurse(price,n,n,dp);
}


//tabulation