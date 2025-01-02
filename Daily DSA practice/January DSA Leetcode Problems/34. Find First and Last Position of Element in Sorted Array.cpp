class Solution
{
public:
    int lowerBound(vector<int> &nums, int target, int n)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> &nums, int target, int n)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lb = lowerBound(nums, target, n);
        if (lb == n || nums[lb] != target)
            return {-1, -1};
        int ub = upperBound(nums, target, n);
        return {lb, ub - 1};
    }
};
//TC = 2*O(logn)

//Simple plance code without any upper bound lower bound concept given below.....

class Solution
{
public:
    int firstOccur(vector<int> &nums, int target, int n)
    {
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    int lastOccur(vector<int> &nums, int target, int n)
    {
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();

        int first = firstOccur(nums, target, n);
        if (first == -1)
            return {-1, -1};
        int last = lastOccur(nums, target, n);
        return {first, last};
    }
};
