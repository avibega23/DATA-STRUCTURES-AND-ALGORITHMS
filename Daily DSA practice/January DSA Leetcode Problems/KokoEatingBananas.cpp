class Solution
{
public:
    int maxFind(vector<int> &arr)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
    long long calculate(vector<int> &piles, int perhour)
    {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            hours += (piles[i] + perhour - 1) / perhour;
        }
        return hours;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = maxFind(piles);

        while (low <= high)
        {
            int mid = (low + high) / 2;

            long long hours = calculate(piles, mid);
            if (hours <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};