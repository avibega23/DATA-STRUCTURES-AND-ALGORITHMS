//https://codeforces.com/problemset/problem/1883/B

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
    int cnt = 0;
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int>hash(26,0);
    for(auto it:s)
    {
        hash[it-'a']++;
    }

    for(int i = 0;i<26;i++)
    {
        if(hash[i]%2 == 1) cnt++; 
    }

    if(cnt  > k +1 ) cout << "NO\n";
    else cout << "YES\n";
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