//https://codeforces.com/problemset/problem/1873/C

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
    vector<vector<int>>nums(10,vector<int>(10,0));
    for(int i = 0;i<10;i++)
    {
        for(int j = 0;j<10;j++)
        {
            char c;
            cin >> c;
            if(c == 'X') nums[i][j] = 1;
        }
    }
    int sum = 0;
    for(int i = 0;i<10;i++)
    {
        for(int j = 0;j<10;j++)
        {
            if(nums[i][j] ==1)
            {
                int  ring = 1 + min({min(i,9-i),min(j,9-j)});
                sum += ring;
            }
        }
    }
    cout << sum << "\n";

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