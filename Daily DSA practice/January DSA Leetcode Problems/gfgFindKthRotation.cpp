int findKRotation(vector<int> &nums)
{
    // Code Here
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int index = -1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            break;
        }
        if (nums[mid] < nums[high])
        {
            if (nums[mid] < ans)
            {
                ans = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
        else
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        }
    }
    return index;