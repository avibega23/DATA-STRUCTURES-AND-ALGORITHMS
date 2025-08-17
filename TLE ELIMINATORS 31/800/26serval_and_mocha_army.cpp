//https://codeforces.com/problemset/problem/1789/A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve() {
    // Write code for one testcase here

    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++) cin >> nums[i];
        bool ok = false;
     for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (__gcd(nums[i], nums[j]) <= 2) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }

        cout << (ok ? "YES\n" : "NO\n");
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