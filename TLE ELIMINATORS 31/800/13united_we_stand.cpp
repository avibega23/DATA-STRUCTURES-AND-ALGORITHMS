//https://codeforces.com/problemset/problem/1859/A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

void solve() {
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++)
    {
        cin >> nums[i];
    }
    bool check = true;
    for(int i = 1;i<n;i++)
    {
        if(nums[i]!=nums[i-1])
        {
            check = false;
            break;
        }
    }
    if(check || n == 1)
    {
        cout << "-1\n";
        return;
    }
    
    sort(nums.begin(),nums.end());
    vector<int>a,b;
    for(int i = 0;i<n;i++)
    {
        if(nums[i]==1) a.push_back(nums[i]);
        else if(a.empty()) a.push_back(nums[i]);
        else if(!a.empty() && nums[i] == a.back()) a.push_back(nums[i]);
        else b.push_back(nums[i]);
    }
    cout << a.size() << " " << b.size() << '\n';
    for(auto it:a)
    {
        cout << it << " ";
    }
    cout << '\n';
    for(auto it:b)
    {
        cout << it << " ";
    }
    cout << '\n';   
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