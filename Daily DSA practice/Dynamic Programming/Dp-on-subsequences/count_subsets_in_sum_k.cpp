//using memoization
int mod = 1e9 + 7;
int recurse(vector<int>&arr,int k,int ind,vector<vector<int>>&dp)
{
	int n = arr.size();
	if(ind == n)
	{
		return (k == 0)?1:0;
	}
	if(dp[ind][k]!=-1) return dp[ind][k];
	int cnt = 0;
	if(k >= arr[ind])
	{
		cnt += recurse(arr,k-arr[ind],ind+1,dp);
		cnt %= mod;
	}
	
	cnt += recurse(arr,k,ind+1,dp);
	cnt %= mod;
	return dp[ind][k] = cnt;
}
int findWays(vector<int>& arr,int k)
{
	// Write your code here.
	vector<vector<int>>dp(arr.size(),vector<int>(k+1,-1));
	return recurse(arr,k,0,dp);
}

//using tabulation