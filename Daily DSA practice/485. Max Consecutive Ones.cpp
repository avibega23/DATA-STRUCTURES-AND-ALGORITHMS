class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int final = INT_MIN;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            final = max(final, cnt);
        }
        return final;
    }
};