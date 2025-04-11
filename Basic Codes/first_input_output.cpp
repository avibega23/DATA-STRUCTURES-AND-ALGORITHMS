#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    string ans = "YES";
    if(n == 0)
    {
        ans = "NO";
    }
    int cnt = 0;
    while(n!=0)
    {
        if(n%10!=7&&n%10!=4)
        {
            ans = "NO";
        }
        cnt++;
        n/=10;
    }
    if(cnt == 4 || cnt == 7)
    {
        ans = "YES";
    }
    cout << ans;
    
    return 0;
}