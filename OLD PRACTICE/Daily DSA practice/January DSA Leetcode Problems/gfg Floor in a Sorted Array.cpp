int floor(vector<int> &arr, int k)
{
    // Your code here
    int low = 0;
    int n = arr.size();
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > k)
        {
            // ans = mid;
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}