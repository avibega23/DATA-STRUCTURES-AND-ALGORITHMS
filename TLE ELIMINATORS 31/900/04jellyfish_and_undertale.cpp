// /https://codeforces.com/problemset/problem/1875/A

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
    int a,b,n;
    cin >> a >> b >> n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++)
    {
        cin >> nums[i];
    }
    int cnt = b;
    for(int i = 0;i<n;i++)
    {
        cnt += min(nums[i],a-1);
    }
    cout << cnt << endl;
    
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