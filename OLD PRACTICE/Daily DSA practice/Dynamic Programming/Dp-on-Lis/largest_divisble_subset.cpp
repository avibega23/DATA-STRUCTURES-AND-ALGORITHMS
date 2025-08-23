//https://leetcode.com/problems/largest-divisible-subset/description/
//recursion + memoization
class Solution {
public:
    vector<int> recurse(vector<int>&nums,int ind,int parent,vector<vector<vector<int>>>&dp)
    {
        int n = nums.size();
        if(ind == n) return {};
        if(!dp[ind][parent+1].empty()) return dp[ind][parent+1];
        vector<int>notTake = recurse(nums,ind+1,parent,dp);

        vector<int>take;
        if(parent == -1 || nums[ind] % nums[parent] == 0)
        {
            take.push_back(nums[ind]);
            for(auto it:recurse(nums,ind+1,ind,dp))
            {
                take.push_back(it);
            }
        }
            

        return dp[ind][parent+1] = (take.size()>=notTake.size())?take:notTake;
        
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1));
        return recurse(nums,0,-1,dp);
    }
};
