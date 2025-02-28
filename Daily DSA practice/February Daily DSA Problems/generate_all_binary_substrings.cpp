//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    void generateAllSubstring(int k, char str[], int ans, vector<string> &ans)
    {
        if (n == k)
        {
            str[n] = '\0';
            ans.push_back(str);
            return;
        }
        if (str[n - 1] == '1')
        {
            str[n] = '0';
            generateAllSubstring(k, str, n + 1, ans);
        }
        if (str[n - 1] == '0')
        {
            str[n] = '0';
            generateAllSubstring(k, str, n + 1, ans);
            str[n] = '1';
            generateAllSubstring(k, str, n + 1, ans);
        }
    }
    vector<string> generateBinaryStrings(int num)
    {
        // Write your code
        vector<string> ans;
        if (num <= 0)
            return ans;
        int n = 1;
        char str[num + 1];
        str[0] = '0';
        generateAllSubstring(num, str, n, ans);
        str[0] = '1';
        generateAllSubstring(num, str, n, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        // Input
        int n;
        cin >> n;

        Solution obj;

        vector<string> v = obj.generateBinaryStrings(n);
        for (auto it : v)
            cout << it << " ";
        cout << endl;

        cout << "~" << "\n";
    }

    return 0;
}

// } Driver Code Ends