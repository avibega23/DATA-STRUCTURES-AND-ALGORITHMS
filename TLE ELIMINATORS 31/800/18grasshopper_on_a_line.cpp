//https://codeforces.com/problemset/problem/1837/A

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
    int x,k;
    cin >> x >> k;

    if(x%k==0)
    {
        cout << 2 << '\n';
        cout << 1 <<  " " << x-1 << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << x << endl;
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