//https://codeforces.com/problemset/problem/1805/A

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
    int x = 0;
    for(int i = 0;i<n;i++)
    {
        cin >> nums[i];
        x = x^nums[i];
    }
    
    if(n%2 == 0)
    {
        if(x == 0) cout << '0' << '\n';
        else cout << -1 << '\n';
    }
    else
    {
        cout << x << '\n';
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