//https://codeforces.com/problemset/problem/1806/A
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
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int cnt = 0;
    cnt = y2-y1;
    if(cnt < 0)
    {
        cout << -1 << '\n';
        return;
    }
    x1 += cnt;
    if(x1 == x2 && y1 == y2)
    {
        cout << cnt << '\n';
        return;
    }
    if(x1 - x2 < 0) 
    {
        cout << -1 << '\n';
        return;
    }
    cout << cnt + x1-x2 << '\n';
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