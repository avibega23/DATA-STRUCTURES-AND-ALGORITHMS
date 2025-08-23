#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin,s);

    if(s[0] >= 'a'&& s[0] <= 'z')
    {
        s[0] = s[0] - 'a' + 'A';
    }
    cout << s;
    return 0;
}