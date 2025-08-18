//https://codeforces.com/problemset/problem/1766/A

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
    int cnt = 0;
    if(n < 10)
    {
        cout << n << endl;
        return;
    }
    while(n>9)
    {
        cnt += 9;
        n /= 10;  
    }
    cout << cnt + n << endl;
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