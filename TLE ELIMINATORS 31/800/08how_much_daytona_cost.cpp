//https://codeforces.com/problemset/problem/1878/A
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
    int n,k;
    bool found = false;
    cin >> n >> k;
    vector<int>nums(n);
    for(int i = 0; i<n; i++)
    {
        cin >> nums[i];
        if(nums[i] == k) found = true;
    }
    cout << (found ? "YES\n" : "NO\n");
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
