class Solution {
    public:
        int maxScore(vector<int>& nums, int k) {
            int n = nums.size();
            int sum = 0;
            int maxi = 0;
            for(int i = 0;i<k;i++)
            {
                sum += nums[i];
            }
            maxi = sum;
            int j = n-1;
            for(int i = k-1;i>=0;i--)
            {
                sum -= nums[i];
                sum += nums[j--];
                maxi = max(maxi,sum);
            }
            return maxi;
        }
    };