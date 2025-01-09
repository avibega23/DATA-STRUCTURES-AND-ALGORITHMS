int floorSqrt(int n)
{
    // Your code goes here
    int low = 0;
    int high = n;
    int ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}