//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int upperBound(vector<int> &nums, int x)
    {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] > x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int blackBox(vector<vector<int>> &mat, int mid)
    {
        int cnt = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            cnt += upperBound(mat[i], mid);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        // code here
        int low = INT_MAX;
        int high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int req = (n * m) / 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            int smallerEquals = blackBox(mat, mid);
            if (smallerEquals <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
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
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends