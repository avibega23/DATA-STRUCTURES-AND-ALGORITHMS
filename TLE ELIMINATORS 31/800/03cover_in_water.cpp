//https://codeforces.com/problemset/problem/1900/A

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
        string s;
        cin >> s;

        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            if((i == 0 || i == n-1) && s[i]=='.') cnt++;
            else if(s[i]=='.' && s[i-1] == '.' && s[i+1] == '.')
            {
                cnt = 2;
                break;
            }
            else if(s[i] == '.') cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
