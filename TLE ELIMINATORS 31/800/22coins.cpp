// /https://codeforces.com/problemset/problem/1814/A

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
    int n , k;
    cin >> n >> k;
    
    if(n % 2 == 0) cout << "YES\n";
    else if(k % 2 != 0)
    {
        if(n >= k) cout << "YES\n";
        else cout << "NO\n";
    }  
    else
    {
        cout << "NO" << endl;
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