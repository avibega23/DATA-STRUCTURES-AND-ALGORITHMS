class Solution
{
public:
    int countPages(vector<int> &nums, int pages)
    {
        int student = 1;
        int cntPages = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] + cntPages) <= pages)
            {
                cntPages += nums[i];
            }
            else
            {
                student++;
                cntPages = nums[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k)
    {
        // code here
        if (arr.size() < k)
            return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (countPages(arr, mid) <= k)
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