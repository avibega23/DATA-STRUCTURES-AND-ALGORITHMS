#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string ans = "YES";
        int i = 0,j = n-1;
        while(i < j)
        {
            if(s[i]!=s[j] && abs((s[i]-'a')-(s[j]-'a'))!=2)
            {
                ans = "NO";
            }
            i++,j--;
        }
        cout << ans << endl;
    }
    return 0;
}