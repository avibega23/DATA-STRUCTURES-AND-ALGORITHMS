//https://codeforces.com/problemset/problem/1881/A


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
        int n,m;
        cin >> n >> m;
        string x,s;
        cin >> x >> s;
        int cnt = 0;
        while(true)
        {
           if (x.find(s) != string::npos) {
                cout << cnt << endl;
                break;
            }
            if (x.size() > n * s.size()) {   
                cout << -1 << endl;
                break;
            }
            x += x;
            cnt++;
        }
    }

    return 0;
}
