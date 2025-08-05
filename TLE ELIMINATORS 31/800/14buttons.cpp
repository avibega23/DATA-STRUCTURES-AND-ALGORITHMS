//https://codeforces.com/problemset/problem/1858/A

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
    vector<int>num(3);
    for(int i = 0;i<3;i++)
    {
        cin >> num[i];
    }
    if(num[0] == num[1])
    {
        if(num[2]%2 == 0) cout << "Second" << '\n';
        else cout << "First" << '\n';
    }
    else if(num[0]>num[1])
    {
        cout << "First" << '\n';
    }
    else
    {
        cout << "Second" << '\n';
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