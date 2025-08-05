//https://codeforces.com/problemset/problem/1853/A

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
    for(int i = 0;i<n;i++)
    {
        cin >> nums[i];
    }
    int mini = INT_MAX;
    for(int i = 1;i<n;i++)
    {
        mini = min(mini,nums[i]-nums[i-1]);
    }
    if(mini == 0) cout << "1";
    else if(mini < 0) cout << "0";
    else
    {
        cout << mini/2 + 1;
    }
    cout << "\n";
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