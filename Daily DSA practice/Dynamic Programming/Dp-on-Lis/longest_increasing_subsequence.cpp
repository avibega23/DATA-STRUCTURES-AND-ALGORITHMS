// reursion + memoization
class Solution {
public:
    int recurse(vector<int>&nums,int ind,int parent,vector<vector<int>>&dp)
    {
        int n = nums.size();
        if(ind == n) return 0;
        if(dp[ind][parent+1]!=-1) return dp[ind][parent+1];

        int nonTake = recurse(nums,ind+1,parent,dp);
        int take = 0;
        if(parent == -1||nums[ind]>nums[parent])
            take = 1 + recurse(nums,ind+1,ind,dp);

        return dp[ind][parent+1] = max({take,nonTake});
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return recurse(nums,0,-1,dp);
    }
};

//tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// binary search
class Solution {
public:
    int upper_bound(vector<int> &arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = mid;
                //look for smaller index on the left
                high = mid - 1;
            }
            else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        
        for(int i = 0;i<n;i++)
        {
            if(ans.empty() || nums[i]>ans[ans.size()-1])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int num = upper_bound(ans,nums[i]);
                // cout << num << " "; 
                if(num < ans.size())
                ans[num] = nums[i];
            }
        }

        return ans.size();
    }
};
