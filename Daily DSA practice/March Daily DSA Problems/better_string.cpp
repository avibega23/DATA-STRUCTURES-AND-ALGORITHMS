//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    void helper(string s, unordered_map<string, int> &mpp, string ans, int i)
    {
        if (i >= s.size())
        {
            mpp[ans]++;
            return;
        }
        helper(s, mpp, ans + s[i], i + 1);
        helper(s, mpp, ans, i + 1);
    }
    string betterString(string str1, string str2)
    {
        // code here
        unordered_map<string, int> mpp1;
        unordered_map<string, int> mpp2;
        helper(str1, mpp1, "", 0);
        helper(str2, mpp2, "", 0);
        return (mpp1.size() >= mpp2.size()) ? str1 : str2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";

        cout << "~" << "\n";
    }
}

// } Driver Code Ends