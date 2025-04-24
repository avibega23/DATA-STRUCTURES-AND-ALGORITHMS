#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans = "";
    int j = 0;
    int number = 2;
    while(j<n)
    {
        ans+=s[j];
        j+=number;
        number++;
    }
    

    cout << ans << endl;
    
    return 0;
}