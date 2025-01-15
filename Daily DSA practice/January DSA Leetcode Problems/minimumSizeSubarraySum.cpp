class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int windowStart = 0;
        int sum = 0;
        int minLength = INT_MAX;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
        {
            sum += nums[windowEnd];

            while (sum >= target)
            {

                minLength = min(minLength, ((windowEnd - windowStart) + 1));

                sum -= nums[windowStart];
                windowStart++;
            }
        }
        if (minLength == INT_MAX)
            return 0;
        return minLength;
    }
};