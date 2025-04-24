#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    string ans = "";
    unordered_set<char>st = {'a','e','i','o','u','A','E','I','O','U','Y','y'};

    for(int i = 0;i<s.size();i++)
    {
        if(st.find(s[i])!=st.end())
        {
            continue;
        }
        if(isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }
        ans += '.';
        ans += s[i];
    }
    cout << ans;
    return 0;
}