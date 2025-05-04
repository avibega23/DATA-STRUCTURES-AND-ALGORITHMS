#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    string s;
    cin >> n >> s;

    for(int i = 0;i<s.size()-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            cout << "YES" << endl;
            string ans = s.substr(i,2);
            cout << ans << endl;
            return 0;
        }

    }
    cout << "NO";
    return 0;
}