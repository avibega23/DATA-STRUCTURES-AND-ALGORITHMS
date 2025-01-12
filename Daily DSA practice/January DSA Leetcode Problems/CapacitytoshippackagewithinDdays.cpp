class Solution
{
public:
    pair<int, int> lowAndHigh(vector<int> &nums)
    {
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }
        return {maxi, sum};
    }
    int reQDays(vector<int> &nums, int capacity)
    {
        int days = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > capacity)
            {
                days++;
                sum = nums[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = lowAndHigh(weights).first;
        int high = lowAndHigh(weights).second;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int reqDays = reQDays(weights, mid);

            if (reqDays <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};