class Solution
{
public:
    int maxIndex(vector<int> &nums)
    {
        int index = -1;
        int maxVal = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        int high = mat.size() - 1;
        int low = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            int maxi = maxIndex(mat[mid]);

            int left = mid - 1 >= 0 ? mat[mid - 1][maxi] : -1;
            int right = mid + 1 < n ? mat[mid + 1][maxi] : -1;

            if (mat[mid][maxi] > left && mat[mid][maxi] > right)
            {
                return {mid, maxi};
            }
            else if (mat[mid][maxi] < left)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};