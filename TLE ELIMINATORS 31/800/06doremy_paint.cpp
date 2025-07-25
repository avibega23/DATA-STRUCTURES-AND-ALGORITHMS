//https://codeforces.com/problemset/problem/1890/A

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
        vector<int>arr(n);
        for(int i = 0;i<n;i++)
        {
            cin >> arr[i];
        }
        unordered_map<int,int>mpp;
        for(auto it:arr)
        {
            mpp[it]++;
        }
        if(mpp.size()==1) cout << "YES\n";
        else if(mpp.size() == 2) {
            vector<int> counts;
            for(auto& p : mpp) counts.push_back(p.second);
            sort(counts.begin(), counts.end());
            if((n % 2 == 0 && counts[0] == counts[1]) ||
               (n % 2 == 1 && counts[1] - counts[0] == 1)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
