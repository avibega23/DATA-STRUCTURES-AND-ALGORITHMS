#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    string ans = "";
    while(n > 0 && n%7!=0) ans.push_back('4'),n-=4;
    while(n > 0 && n%7==0) ans.push_back('7'),n-=7;
    if(n==0) cout << ans << endl;
    else cout << -1;


    return 0;
}