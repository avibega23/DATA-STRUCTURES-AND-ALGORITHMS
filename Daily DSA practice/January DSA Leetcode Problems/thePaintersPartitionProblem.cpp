//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int cntPainters(vector<int> &nums, int time)
    {
        int currPainters = 1;
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] + last > time)
            {
                currPainters++;
                last = nums[i];
            }
            else
            {
                last += nums[i];
            }
        }
        return currPainters;
    }
    int minTime(vector<int> &arr, int k)
    {
        // code here
        // return minimum time
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (cntPainters(arr, mid) <= k)
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

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends