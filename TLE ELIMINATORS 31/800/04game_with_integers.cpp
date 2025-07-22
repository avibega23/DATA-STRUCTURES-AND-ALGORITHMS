//https://codeforces.com/problemset/status?my=on
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

int32_t main() {
    fast_io

    // Your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n%3 ==1 || n % 3 == 2) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}
