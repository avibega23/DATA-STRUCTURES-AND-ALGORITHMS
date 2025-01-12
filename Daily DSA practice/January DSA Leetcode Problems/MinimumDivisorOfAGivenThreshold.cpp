class Solution
{
public:
    int findMax(vector<int> &nums)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(nums[i], maxi);
        }
        return maxi;
    }
    bool possible(vector<int> &nums, int mid, int threshold)
    {
        double sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / (double)mid);
        }
        if (sum <= threshold)
            return true;
        return false;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int high = findMax(nums);
        int low = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (possible(nums, mid, threshold))
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