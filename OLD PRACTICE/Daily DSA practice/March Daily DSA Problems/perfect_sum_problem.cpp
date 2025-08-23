//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int helper(vector<int> &arr, int target, int sum, int index)
    {
        if (index >= arr.size())
        {
            if (sum == target)
            {
                return 1;
            }
            return 0;
        }
        int l = helper(arr, target, sum + arr[index], index + 1);
        int r = helper(arr, target, sum, index + 1);
        return l + r;
    }
    int perfectSum(vector<int> &arr, int target)
    {
        // code here
        return helper(arr, target, 0, 0);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--)
    {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value)
        {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends