
class Solution
{
public:
    bool possible(vector<int> &nums, int cows, int dist)
    {
        int cowCnt = 1;
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - last >= dist)
            {
                cowCnt++;
                last = nums[i];
            }
            if (cowCnt >= cows)
                return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {

        // Write your code here
        sort(stalls.begin(), stalls.end());

        int high = stalls[stalls.size() - 1];
        int mini = stalls[0];
        high = high - mini;

        int low = 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (possible(stalls, k, mid) == true)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};