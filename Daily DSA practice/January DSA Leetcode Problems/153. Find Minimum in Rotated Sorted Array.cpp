class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int mini = INT_MAX;
        int low = 0;
        int n = nums.size();
        int high = n - 1;

        while (low <= high)
        {
            if (nums[low] <= nums[high])
            {
                mini = min(mini, nums[low]);
                break;
            }
            int mid = low + (high - low) / 2;

            if (nums[mid] <= nums[high])
            {
                if (nums[mid] <= mini)
                {
                    mini = nums[mid];
                }
                high = mid - 1;
            }
            else
            {
                if (nums[low] <= mini)
                {
                    mini = nums[mid];
                }
                low = mid + 1;
            }
        }
        return mini;
    }
};