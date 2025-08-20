//https://codeforces.com/problemset/problem/1904/A

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
    vector<int>first = {1,-1,1,-1};
    vector<int>second = {1,-1,-1,1};
    set<pair<int,int>>st1;
    set<pair<int,int>>st2;


    int a,b,x1,y1,x2,y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    for(int i = 0;i<4;i++)
    {
        int pos1 = x1 + (first[i]*a);
        int pos2 = y1 + (second[i]*b);

        st1.insert({pos1,pos2});
    }
    for(int i = 0;i<4;i++)
    {
        int pos1 = x1 + (first[i]*b);
        int pos2 = y1 + (second[i]*a);

        st1.insert({pos1,pos2});
    }


    for(int i = 0;i<4;i++)
    {
        int pos1 = x2 + (first[i]*a);
        int pos2 = y2 + (second[i]*b);

        st2.insert({pos1,pos2});
    }
    for(int i = 0;i<4;i++)
    {
        int pos1 = x2 + (first[i]*b);
        int pos2 = y2 + (second[i]*a);

        st2.insert({pos1,pos2});
    }
    int forkCount = 0;
    for(auto p:st1)
    {
        if(st2.count(p)) forkCount++;
    }
    cout << forkCount << endl;
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