//https://codeforces.com/problemset/problem/1866/A

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
    int mini = INT_MAX;
    for(int i = 0;i<n;i++)
    {
        int num;
        cin >> num;
        if(num < 0) mini = min(mini,-num);
        else mini = min(mini,num); 
    }
    cout << mini << '\n';
}

int32_t main() {
    fast_io;
    int t = 1;
    // cin >> t;   // Comment if only 1 test case
    while (t--) {
        solve();
    }
    return 0;
}   