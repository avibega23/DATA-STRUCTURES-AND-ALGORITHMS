//https://codeforces.com/contest/1878/problem/C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define uniq(x) x.erase(unique(all(x)), x.end())

void solve() {
    // Write code for one testcase here
    int n,k,x;
    cin >> n >> k >> x;

    int mini = (k * (k+1)) / 2;
   
    int maxi = ((n*(n+1))/2) - (((n-k)*(n-k+1))/2);
   
    if(x >= mini && x <= maxi)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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