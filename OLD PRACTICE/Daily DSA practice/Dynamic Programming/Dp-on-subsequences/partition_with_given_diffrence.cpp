//recursive solution
class Solution {

  public:
    int recurse(vector<int>&arr,int ind,int target)
    {
        if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
        }
        int take = recurse(arr,ind-1,target-arr[ind]);
        int nonTake = recurse(arr,ind-1,target);
        return take+nonTake;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(auto it:arr)
        {
            sum+=it;
        }
        int target = (sum+d)/2;
        if((sum-d)<0) return 0;
        if((sum-d)%2==1) return 0;
        return recurse(arr,n-1,target);
    }
};

//memoization solution
class Solution {
  public:
    int mod = 1e9 + 7;
    int recurse(vector<int>&arr,int ind,int target,vector<vector<int>>&dp)
    {
        if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int take = 0; 
        if(arr[ind]<=target) take =  recurse(arr,ind-1,target-arr[ind],dp);
        int nonTake = recurse(arr,ind-1,target,dp);
        return dp[ind][target] = take+nonTake;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(auto it:arr)
        {
            sum+=it;
        }
        int target = (sum+d)/2;
        if((sum-d)<0) return 0;
        if((sum-d)%2==1) return 0;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return recurse(arr,n-1,target,dp);
    }
};


//tabulation solution
class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(auto it:arr)
        {
            sum+=it;
        }
        
        int target = (sum+d)/2;
        if((sum+d)<0) return 0;
        if((sum+d)%2==1) return 0;
        
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        for(int i = 0;i<n;i++)
        {
            dp[i][0] = 1;
        }
        
        if(arr[0]==0) dp[0][0] = 2;
        else if(arr[0] <= target) dp[0][arr[0]] = 1;
        for(int i = 1;i<n;i++)
        {
            for(int t = 0;t<=target;t++)
            {
                int notTake = dp[i-1][t];
                int take = 0;
                if(arr[i]<=t)
                {
                    take = dp[i-1][t-arr[i]];
                }
                
                dp[i][t] = notTake + take;
            }
        }
        return dp[n-1][target];
    }
};