//https://codeforces.com/problemset/problem/1862/B

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
    vector<int>ans;
    for(int i  = 0;i<n;i++)
    {
        int num;
        cin >> num;
        if(i == 0) ans.push_back(num);
        else
        {
            if(ans.back()<=num) ans.push_back(num);
            else
            {
                ans.push_back(num);
                ans.push_back(num);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto it:ans)
    {
        cout << it << " ";
    }
    cout << endl;
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