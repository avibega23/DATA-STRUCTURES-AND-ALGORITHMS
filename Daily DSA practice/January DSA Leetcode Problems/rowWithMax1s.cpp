class Solution
{
public:
    int lowerBoundd(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size();
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == 1)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return (nums.size() - low);
    }
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        int maxVal = -1;
        int maxIndex = -1;
        for (int i = 0; i < n; i++)
        {
            int cnt = lowerBoundd(arr[i]);
            if (cnt > maxVal)
            {
                maxVal = cnt;
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};