//https://codeforces.com/problemset/problem/1791/C

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
    string s;
    cin >> s;
    int i = 0 , j = s.size()-1;

    int cnt = 0;
    while(i <= j)
    {   
        if(s[i]!=s[j]) cnt +=2;
        else break;
        i++;
        j--;
    }

    cout << n-cnt << endl;
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