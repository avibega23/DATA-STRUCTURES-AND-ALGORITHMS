class Solution
{
public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr)
    {
        // Your code goes here
        // int i = 0;
        int j = 1;
        int sum = INT_MIN;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] + arr[i + 1] >= sum)
            {
                sum = arr[i] + arr[i + 1];
            }
        }
        return sum;
    }
};