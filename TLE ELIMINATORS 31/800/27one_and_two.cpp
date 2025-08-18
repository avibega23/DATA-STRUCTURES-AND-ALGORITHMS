//https://codeforces.com/problemset/problem/1788/A?csrf_token=01374c656756d8903c1e7d3d3b728577

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

void solve() {
    // Write code for one testcase here
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int &x:nums) cin >> x;

    int total_two = 0;
    for(int x:nums) if(x == 2) total_two++;

    if(total_two % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    int half = total_two / 2;
    int prefix_two = 0;
    for(int i = 0;i<n-1;i++)
    {
        if(nums[i] == 2)
        {
            prefix_two++;
        }
        if(prefix_two == half)
        {
            cout << i+1 << endl;
            return;
        }
    }
}

int32_t main() {
    fast_io;
    int t = 1;
    cin >> t;   // Comment if only 1 test case
    while (t--) {
        solve();
    }
    return 0;
}