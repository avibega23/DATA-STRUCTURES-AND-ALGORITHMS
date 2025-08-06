//https://codeforces.com/problemset/problem/1845/A

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
    int n,k,x;
    cin >> n >> k >> x;
    vector<int>nums(n);
    if(k == 1 && x == 1)
    {
        cout << "NO" << '\n';
        return;
    }

    if(x!=1)
    {
        cout << "YES\n";
        cout << n << '\n';
        for(int i = 0;i<n;i++)
        {
            cout << "1" <<  " ";
        }
        cout << "\n";
    }
    else
    {
        if(k<2)
        {
            cout << "NO\n";
            return;
        }

        if(n%2 == 0)
        {
            cout << "YES\n";
            cout << n/2 << '\n';
            for(int i = 0;i<n/2;i++)
            {
                cout << 2 << " ";
            }
            cout << '\n';
        }
        else
        {
            if(k >= 3)
            {
                cout << "YES\n";
                cout << (n-3)/2 +1 << '\n';
                for(int i = 0;i<(n-3)/2;i++)
                {
                    cout << "2" << " ";
                }
                cout << "3\n";
            }
            else
            {
                cout << "NO\n"; 
            }
        }
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